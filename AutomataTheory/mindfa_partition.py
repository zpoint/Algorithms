import copy


class Table(object):
    def __init__(self):
        self.states = list()
        self.entry = dict()
        self.inputs = list()
        self.begin_state = None
        self.end_state = None


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
                same_partition = False
                for new_each_set in new_sets:
                    new_set_state = None
                    for _ in new_each_set:
                        new_set_state = _
                        break
                    states_a, states_b = self.entry[state], self.entry[new_set_state]
                    for state_a, state_b in zip(states_a, states_b):
                        for each_set in states_sets:
                            if state_a in each_set:
                                if state_b in each_set:
                                    same_partition = True
                                    break
                            elif state_b in each_set:
                                if state_a in each_set:
                                    same_partition = True
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
            if curr_sets == prev_sets:
                break
            # continue partition prev_set
            curr_sets = self.partiton(prev_sets)
            if curr_sets == prev_sets:
                break
            prev_sets = curr_sets
