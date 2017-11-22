from collections import OrderedDict


class Table(object):
    inputs = [0, 1]

    def __init__(self):
        self.symbols = list()
        self.entry = OrderedDict()

    def __str__(self):
        ret_str = ""
        for symbol in self.entry:
            ret_str += symbol + ": |"
            for i in self.entry[symbol]:
                ret_str += ",".join(i) + "| "
            ret_str += "\n"
        return ret_str


class NFATable(Table):
    symbols = ["A", "B", "C", "~"]
    start_symbol = "A"
    end_symbol = "C"
    
    def __init__(self):
        super().__init__()
        self.entry["A"] = [["A"], ["A", "B"]]
        self.entry["B"] = [["C"], ["C"]]
        self.entry["C"] = [["~"], ["~"]]


def nfa2dfa(nfa_table):
    dfa_table = Table()
    dfa_table.entry[nfa_table.start_symbol] = []
    queue = list()
    need_dead_state = False

    for targets in nfa_table.entry[nfa_table.start_symbol]:
        target_symbol = "".join(targets)
        dfa_table.entry[nfa_table.start_symbol].append(target_symbol)
        queue.append(target_symbol)

    while len(queue) > 0:
        symbol = queue.pop()
        if symbol in dfa_table.entry:
            continue
        if symbol in nfa_table.entry:
            # single symbol
            for targets in nfa_table.entry[symbol]:
                if len(targets) > 1 and "~" in targets:
                    targets = [i for i in targets if i != "~"]
                target_symbol = "".join(targets)
                dfa_table.entry[symbol].append(target_symbol)
                if target_symbol not in queue:
                    queue.append(target_symbol)
        else:
            # combined symbol
            dfa_table.entry[symbol] = list()
            for index in range(len(nfa_table.inputs)):
                if symbol == "~":
                    dfa_table.entry[symbol].append("DEAD")
                    need_dead_state = True
                    continue

                union_set = set()
                for char in symbol:
                    for i in nfa_table.entry[char][index]:
                        union_set.add(i)
                union_set = list(union_set)

                if len(union_set) > 1 and "~" in union_set:
                    union_set = [i for i in union_set if i != "~"]

                target_symbol = "".join(union_set)
                dfa_table.entry[symbol].append(target_symbol)
                if target_symbol not in queue:
                    queue.append(target_symbol)
    if need_dead_state:
        dfa_table["DEAD"] = [["DEAD"] for _ in range(len(dfa_table.inputs))]
    return dfa_table


if __name__ == "__main__":
    a = NFATable()
    print(a)
    b = nfa2dfa(a)
    print(b)

