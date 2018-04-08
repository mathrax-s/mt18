/* 
 * File:   wavetable.h
 * Author: shozo@kuze.jp
 *
 * Created on 4/8/2018 1:31:56 AM UTC
 * "Created in MPLAB Xpress"
 */

#ifndef WAVETABLE_H
#define	WAVETABLE_H

unsigned char waveTable[256]={
152,199,234,253,253,234,199,152,103,56,21,2,2,21,56,103,152,199,234,253,253,234,199,152,103,56,21,2,2,21,56,103
};


unsigned char envelopeTable[] = {
// 20,60,100,127,127,126,126,125,125,124,124,123,123,122,122,121,121,120,120,119,119,118,118,117,117,116,116,115,115,114,114,113,113,112,112,111,111,110,110,109,109,108,108,107,107,106,105,105,104,104,103,103,102,102,101,101,100,100,99,99,98,98,97,97,96,96,95,95,94,94,93,93,92,92,91,91,90,90,89,89,88,88,87,87,86,86,85,85,84,84,83,83,82,82,81,81,80,80,79,79,78,78,77,77,76,75,75,74,74,73,73,72,72,71,71,70,70,69,69,68,68,67,67,66,66,65,65,64,64,63,63,62,62,61,61,60,60,59,59,58,58,57,57,56,56,55,55,54,54,53,53,52,52,51,51,50,50,49,49,48,48,47,47,46,46,45,44,44,43,43,42,42,41,41,40,40,39,39,38,38,37,37,36,36,35,35,34,34,33,33,32,32,31,31,30,30,29,29,28,28,27,27,26,26,25,25,24,24,23,23,22,22,21,21,20,20,19,19,18,18,17,17,16,16,15,14,14,13,13,12,12,11,11,10,10,9,9,8,8,7,7,6,6,5,5,4,4,3,3,2,2,1,1,0,0
  127,  124,  121,  119,  116,  113,  111,  109,  106,  104,  102,  100,   97,   95,   93,   91,
  89,   87,   85,   84,   82,   80,   78,   77,   75,   73,   72,   70,   69,   67,   66,   64,
  63,   62,   60,   59,   58,   56,   55,   54,   53,   52,   51,   50,   48,   47,   46,   45,
  44,   43,   42,   42,   41,   40,   39,   38,   37,   36,   36,   35,   34,   33,   33,   32,
  31,   31,   30,   29,   29,   28,   27,   27,   26,   26,   25,   25,   24,   23,   23,   22,
  22,   21,   21,   21,   20,   20,   19,   19,   18,   18,   18,   17,   17,   16,   16,   16,
  15,   15,   15,   14,   14,   14,   13,   13,   13,   13,   12,   12,   12,   11,   11,   11,
  11,   10,   10,   10,   10,   10,    9,    9,    9,    9,    9,    8,    8,    8,    8,    8,
  7,     7,    7,    7,    7,    7,    6,    6,    6,    6,    6,    6,    6,    5,    5,    5,
  5,     5,    5,    5,    5,    5,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
  3,     3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,    2,    2,
  2,     2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
  1,     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
  1,     1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
  0,     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  0,     0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
};


    
unsigned char onkai_d[] = {
6,
6,
7,
7,
7,
8,
8,
9,
10,
10,
11,
11,
12,
13,
14,
15,
15,
16,
17,
18,
20,
21,
22,
23,
25,
26,
28,
30,
31,
33,
35,
37,
40,
42,
45,
47,
50,
53,
56,
60,
63,
67,
71,
75,
80,
85,
90,
95,
101,
107,
113,
120,
127,
135,
143,
151,
160,
170,
180,
190,
202,
214,
227,
240,
254,
};


//????????????(????????????)
unsigned char onkai_f[] = {
11,
23,
4,
17,
31,
15,
31,
16,
2,
21,
9,
30,
21,
13,
7,
2,
30,
29,
29,
31,
3,
9,
17,
28,
10,
26,
13,
3,
28,
25,
25,
29,
5,
17,
2,
24,
19,
19,
25,
5,
24,
17,
17,
25,
9,
2,
4,
16,
5,
6,
18,
10,
15,
1,
2,
18,
18,
4,
8,
31,
10,
11,
3,
19,
29,
};

#endif	/* WAVETABLE_H */