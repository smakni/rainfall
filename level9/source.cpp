# include <iostream>
# include <stdlib.h>
# include <cstring>
using namespace std;

class N {
	public:
		char dst[100];
		int nb;

		N(int n) {
			nb = n;
		}

		void setAnnotation(char *src) {
			memcpy(dst, src, strlen(src));
		}

		virtual int operator+(N &n) {
			return (nb + n.nb);
		}

		virtual int operator-(N &n) {
			return (nb - n.nb);
		}
};

int main (int argc, char **argv) {

	if (argc <= 1) {
		exit(1);
	}
	
	N *n1 = new N(5);
	N *n2 = new N(6);

	N *n1_ptr = n1;
	N *n2_ptr = n2;

	n1_ptr->setAnnotation(argv[1]);
	
	return (*n2_ptr + *n1_ptr);

	// si + non changé on aurai (classe_n2 + class_n1) >> impossible
	// mais on a un operator overloading dans N
	// donc n2 appel sa fonction + (nb + n.nb) avec comme argument n = *n1_ptr
	// cad nb de n2 donc 6 + n.nb de n1 donc 5
	// >> (6 + 5)
}