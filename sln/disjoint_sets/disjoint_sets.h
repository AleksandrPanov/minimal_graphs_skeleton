#pragma once
class DisjoinSet
{
private:
	//struct
public:
	int create(int x);
	int find(int x);
	void doUnion(int a, int b);
};