#include "dialog.cpp"

int main()
{
    int error;
    while(true){
        error = menu();
        if(error == 1 || error == 2) break;
    }
	exit(0);
}
