#include <bits/stdc++.h>
using namespace std;

static mutex exclusive;
void single_count(int *begin, int *end, int counts[], int max_value) {
	int *local_counts = new int[max_value+1];
	fill(local_counts, local_counts+max_value+1, 0);
	for (int *p = begin; p != end; ++p) {
		++local_counts[*p];
	}
	exclusive.lock();
	for (int i = 0; i <= max_value; ++i) {
		counts[i] += local_counts[i];
	}
	exclusive.unlock();
	delete[] local_counts;
}
void parallel_count(int array[], int array_size, int counts[], int max_value) {
	thread *threads[4];
	int cur = 0;
	for (int i = 0, nxt; i < 4; ++i) {
		nxt = min(array_size, cur+array_size/4+1);
		threads[i] = new thread(single_count, array+cur, array+nxt, counts, max_value);
		cur = nxt;
	}
	for (int i = 0; i < 4; ++i) {
		threads[i]->join();
	}
	for (int i = 0; i < 4; ++i) {
		delete threads[i];
	}
}
