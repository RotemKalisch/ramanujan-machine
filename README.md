# ramanujan-machine
The ramanujan machine (http://www.ramanujanmachine.com/) is a pretty cool way to generate mathematical equations.
I took the challenge of implementing such a machine in C++ while i was sick with the coronavirus.
It took me around 3 days to get to an initial working state.

## TODOs
### Development
1. Make the `MeetMap` object something persistant, i.e a DB.
2. Add more complex `NumberGenerator`s (*a\_n* and *b\_n*).
3. Receive parameters through commandline instead of them being hardcoded.
4. Use a logger instead of printing to terminal (LOL).
5. Figure out a way to distribute the algorithm.
6. Performance testing and benchmarking

### Research
1. Optimize thresholds for enumeration.
2. Find a pattern in this phenomena:
    a. what is the likelyhood to find a continued fraction that matches a mobius value,
       as a function of the constant used (pi, e, log2 etc) and the size of the numbers?
    b. what is the consistency of continued fractions that match a mobius value,
       as a function of the complexity of the `NumberGenerator`s?
