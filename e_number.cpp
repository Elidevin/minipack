#include <iostream>
#include <string>

std::string e_number(int accuracy = 600){
	int size = accuracy + 11, i, c, p, n;
	int a[size], b[size], e[size];
	e[0] = b[0] = 1;
	for(i=1; i<size; ++i)
		a[i] = b[i] = e[i] = 0;
	/* ----------- */
	for(n=1; n<size; ++n){
		for(i=0; i<size; ++i)
			a[i] = b[i];
		c = a[0];
		for(i=0; i<size-1; ++i){
			b[i] = c / n;
			c = (c - n * b[i]) * 10 + a[i + 1];
		}
		p = 0;
		for(i=size-1; i>=0; --i){
			c = e[i] + b[i] + p;
			p = 0;
			if(c < 10) e[i] = c;
			else{
				e[i] = c - 10;
				p = 1;
			}
		}
	}
	/* ----------- */
	std::string result = std::to_string(e[0]) + '.';
	for(i=1; i<size-10; ++i)
		result += std::to_string(e[i]);
	return result;
}

int main(int args, char* argv[]){
	int accuracy = 100;
	if(args > 1) accuracy = std::atoi(argv[args-1]);
	std::cout << e_number(accuracy) << std::endl;
	return 0;
}