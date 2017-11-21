#### Automata Theory

##### Video Hint
* [DFA](https://www.youtube.com/watch?v=40i4PKpM0cI&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev&index=4)
* [NFA](https://www.youtube.com/watch?v=egXhe55dAIk&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev&index=11)
* [Conversion of NFA to DFA](https://www.youtube.com/watch?v=--CSVsFIDng&index=15&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev)
* Minimization of DFA
    * [Partitioning Method](https://www.youtube.com/watch?v=hOzc4BUIXRk&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev&index=20)
    * [Table Filling Method](https://www.youtube.com/watch?v=UiXkJUTkp44&index=25&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev)


##### Implementation
* DFA
	* ![DFA graph](https://github.com/zpoint/Algorithms/blob/master/AutomataTheory/screenshots/dfa.png)


            gcc dfa.c
            ./a.out
            Please enter strings only contains 0, 1, I will match all string start with 0
            110
            Not accepted
            0001
            In the accepted state
            010000
            In the accepted state
            011110110101010
            In the accepted state
            100
            Not accepted

* NFA
	* ![NFA graph](https://github.com/zpoint/Algorithms/blob/master/AutomataTheory/screenshots/nfa.png)


			gcc nfa.c
            ./a.out
            Please enter strings only contains 0, 1, I will match all string contain '01'
            000
            Not accepted
            111
            Not accepted
            11110
            Not accepted
            01
            Accepted
            00010
            Not accepted
            00001
            Accepted

