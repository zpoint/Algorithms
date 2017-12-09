import copy
from collections import OrderedDict


class Table(object):
    def __init__(self):
        self.states = list()
        self.entry = OrderedDict()
        self.inputs = list()
        self.begin_state = None
        self.end_state = None

    def __str__(self):
        ret_str = ""
        for symbol in self.entry:
            ret_str += symbol + ": |"
            for i in self.entry[symbol]:
                ret_str += ",".join(i) + "| "
            ret_str += "\n"
        return ret_str


class DfaTable(Table):
    def __init__(self):
        super().__init__()
        self.inputs = [0, 1]
        self.states = ["A", "B", "C", "D", "E", "F"]
        self.begin_state = "A"
        self.end_state = {"C", "D", "E"}
        self.entry["A"] = ["B", "C"]
        self.entry["B"] = ["A", "D"]
        self.entry["C"] = ["E", "F"]
        self.entry["D"] = ["E", "F"]
        self.entry["E"] = ["E", "F"]
        self.entry["F"] = ["F", "F"]

    def minimize_table_fill(self):
        self.min_table = OrderedDict()
        for i in self.states:
            for j in self.states:
                if i == j:
                    continue
                pre_order = "".join((i, j))
                post_order = "".join((j, i))
                if pre_order in self.min_table or post_order in self.min_table:
                    continue
                # step 2
                if not (i in self.end_state and j in self.end_state) and (i in self.end_state or j in self.end_state):
                    self.min_table[pre_order] = True
                else:
                    self.min_table[pre_order] = False

        # step 3
        need_repeat = True
        while need_repeat:
            need_repeat = False
            for pair in self.min_table:
                if not self.min_table[pair]:
                    for input_index in range(len(self.inputs)):
                        state_a, state_b = self.entry[pair[0]][input_index], self.entry[pair[1]][input_index]
                        if state_a == state_b:
                            continue
                        pre_order = "".join((state_a, state_b))
                        post_order = "".join((state_b, state_a))
                        pre_order = pre_order if pre_order in self.min_table else post_order
                        if self.min_table[pre_order]:
                            if not need_repeat:
                                need_repeat = True
                            self.min_table[pair] = True

        # combine all unmarked pairs
        need_combine_pair = set()
        combined_states = list()
        combined_state_map = {state: state for state in self.states}
        new_table = Table()
        new_table.inputs = copy.deepcopy(self.inputs)
        for pair in self.min_table:
            if not self.min_table[pair]:
                need_combine_pair.add(pair)
        for pair in need_combine_pair:
            if not combined_states:
                combined_states.append(list(pair))
                continue
            has_same_combined_state = False

            for each_combined_state in combined_states:
                if has_same_combined_state:
                    break
                for state in pair:
                    if state in each_combined_state:
                        each_combined_state.extend(list(pair))
                        has_same_combined_state = True
                        break
            if not has_same_combined_state:
                combined_states.append(list(pair))

        for i in range(len(combined_states)):
            combined_states[i] = set(combined_states[i])
        for states in combined_states:
            combined_state_name = "".join(states)
            new_table.states.append(combined_states)
            for state in states:
                combined_state_map[state] = combined_state_name
        for final_state_name in set(combined_state_map.values()):
            new_table.entry[final_state_name] = list()
            for input_index in range(len(new_table.inputs)):
                new_table.entry[final_state_name].append(combined_state_map[self.entry[final_state_name[0]][input_index]])
        return new_table


if __name__ == "__main__":
    a = DfaTable()
    print(a)
    b = a.minimize_table_fill()
    print(b)
