#define CHAR_SIZE 8
#define MAX_BIGSET 125
#define MAX_VAL (CHAR_SIZE * MAX_BIGSET)

typedef unsigned char BIGSET[MAX_BIGSET];



 void BIGSET_init(BIGSET s){
 	for(int i = 0; i< MAX_BIGSET ; i++){
 		s[i] = 0;
 	}

 }

void BIGSET_add(BIGSET s, int i){
	int num_case = n/8;
	int num_bit = n%8;

	case[num_case] = case [num_case] | 1<< num_bit;
}

int BIGSET_is_in(BIGSET s, int i){
	int i
}