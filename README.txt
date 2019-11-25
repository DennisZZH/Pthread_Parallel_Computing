Last name of Student 1: Zhang
First name of Student 1: Zihao
Email of Student 1: zihaozhang@ucsb.edu
Last name of Student 2: Lin
First name of Student 2: Tiancheng
Email of Student 2: tianchenglin@ucsb.edu



Report for Question 3 with Test 3.a

				Blockmapping		block cyclic(r=1)		block cyclic(r=16)

Sequential:		20.422				20.437					20.426

2 threads:		10.417				10.580					10.404
  Speedup:		1.965				1.936					1.969
  Efficiency:	0.982				0.968					0.984		

4 threads:		5.821				6.027					5.776
  Speedup:		3.514				3.396					3.547
  Efficiency:	0.877				0.848					0.884


Explanation: 
Blockmapping produced a good performance because regular (non-upper triangular) matrixs are used in this test, the work distribution is even. 
Block cyclic (r = 1) is slow because when multiple thread cooperate closely on one data block, false sharing may occur and lower the efficiency.
Block cyclic (r = 16) also produce a good performance because no false sharing and even work distribution.
In conclusion, blockmapping and block cyclic(r = 16) both give good performance for this test.


Report for Question 3 with Test 3.b


				Blockmapping		block cyclic(r=1)		block cyclic(r=16)

Sequential:		0.08383				0.08378					0.08374

2 threads:		0.0619				0.0424					0.0412
  Speedup:		1.354				1.976					2.033
  Efficiency:	0.677				0.988					1.017		

4 threads:		0.0370				0.0244					0.0226
  Speedup:		2.266				3.434					3.705
  Efficiency:	0.567				0.859					0.926


Explanation: 
Clearly, Blockmapping is much slower because upper triangular matrix is used in the test thus the work distribution is uneven in the blockmapping.
Some threads get more tasks and take more time to finish when some threads idle.
Block cyclic(r = 1) has even work distribution, but still suffers from falsing sharing problem. This is why it is faster than blockmapping but slower than block cyclic(r = 16)
Block cyclic(r = 16) has even work distribution and no false sharing, thus having the best performance.
In conclusion, block cyclic(r = 16) gives the best performance in this test.