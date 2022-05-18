# sas_cpp_floodfill
a shitty recursive function text based flood fill to practise with.

It'll first ask you for 2 input numbers, seperated by a comma. do not include spaces.
Then, it'll perform floodfill on image.txt, with whatever number it landed on.

Sample output:

Sample coordinate, e.g. 1,2: 4,5
[4 , 5 ]
'image' to fill, starting at [4 , 5 ]

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 1 1
0 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 1 0 0 0 1
0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

============================================

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 4 4 4 0 0 0 0 0
0 0 0 0 0 0 0 4 4 4 4 4 4 4 4 0 0 0 0 4 4
0 0 0 0 4 4 4 4 4 0 0 0 4 4 4 4 4 0 0 0 4
0 0 0 0 0 0 4 4 4 4 4 4 4 4 4 0 0 0 4 4 4
4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 4 4 4 4 4
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
