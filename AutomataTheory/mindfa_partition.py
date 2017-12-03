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
        self.states = ["A", "B", "C", "D", "E"]
        self.begin_state = "A"
        self.end_state = "E"
        self.entry["A"] = ["B", "C"]
        self.entry["B"] = ["B", "D"]
        self.entry["C"] = ["B", "C"]
        self.entry["D"] = ["B", "E"]
        self.entry["E"] = ["B", "C"]

    def partition(self, states_sets):
        new_sets = list()
        for origin_each_set in states_sets:
            if len(origin_each_set) == 1:
                new_sets.append(copy.deepcopy(origin_each_set))
                continue
            for state in origin_each_set:
                if not new_sets:
                    new_sets.append({state})
                    continue
                for new_each_set in new_sets:
                    same_partition = True
                    new_set_state = None
                    for _ in new_each_set:
                        new_set_state = _
                        break
                    states_a, states_b = self.entry[state], self.entry[new_set_state]
                    for state_a, state_b in zip(states_a, states_b):
                        for each_set in states_sets:
                            if state_a in each_set:
                                if state_b not in each_set:
                                    same_partition = False
                                    break
                            elif state_b in each_set:
                                if state_a not in each_set:
                                    same_partition = False
                                    break
                    if same_partition:
                        new_each_set.add(state)
                        break
                if not same_partition:
                    new_sets.append({state})
        return new_sets

    def minimize_partition(self):
        prev_sets = list()
        curr_sets = list()
        # construct first partition table
        set_a, set_b = set(), set()
        for state in self.states:
            if state != self.end_state:
                set_a.add(state)
            else:
                set_b.add(state)
        prev_sets.append(set_a)
        prev_sets.append(set_b)
        while True:
            # continue partition prev_set
            curr_sets = self.partition(prev_sets)
            if curr_sets == prev_sets:
                break
            prev_sets = curr_sets
        # combine states in same sets
        new_table = Table()
        new_table.inputs = copy.deepcopy(self.inputs)
        output_node_map = dict()
        for each_set in curr_sets:
            node_name = "".join(each_set)
            for node in each_set:
                output_node_map[node] = node_name

        dest_table = dict()
        for each_set in curr_sets:
            new_state = "".join(each_set)
            for state in each_set:
                dest_table[state] = new_state

        for each_set in curr_sets:
            new_state = "".join(each_set)
            new_table.entry[new_state] = list()
            one_state_in_each_set = None
            for i in each_set:
                one_state_in_each_set = i
                break
            for input_index in range(len(self.inputs)):
                dest = dest_table[self.entry[one_state_in_each_set][input_index]]
                new_table.entry[new_state].append(dest)

            if self.begin_state in each_set:
                new_table.begin_state = new_state
            if self.end_state in each_set:
                new_table.end_state = new_state
        return new_table


if __name__ == "__main__":
    a = DfaTable()
    print(a)
    b = a.minimize_partition()
    print(b)
