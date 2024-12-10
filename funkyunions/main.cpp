#include <iostream>
typedef union REQ_T {
    struct SEL_T {
        int funcnum;
        int data[7];
    } sel;
    struct F1_T {
        int funcnum;
        double ddd;
    } f1;
    struct F2_T {
        int funcnum;
        long lll;
    } f2;
 } req;

req Req;

void handler1(REQ_T *Req)
{
    printf("function one data was %8.3f\n",Req->f1.ddd);
}

void handler2(REQ_T *Req)
{
    printf("function two data was %ld\n",Req->f2.lll);
}


void handler(REQ_T *Req)
{
   switch(Req->sel.funcnum) {
       case 1: handler1(Req); break;
       case 2: handler2(Req); break;
       default: printf("invalid function\n");
   }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Req.f1.funcnum = 1;
    Req.f1.ddd = 1.1;
    handler(&Req);

    Req.sel.funcnum = 2;
    Req.f2.lll = 65535l;
    handler(&Req);

    return 0;
}
