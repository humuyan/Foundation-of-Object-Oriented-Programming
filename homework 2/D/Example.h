#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	
	// (1)
	static int cnt;
	int id, data;
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif
