#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h> // for ntohl

uint32_t add_fun(uint32_t n1, uint32_t n2, uint32_t result ){
    
    // ntohl 
    n1 = ntohl(n1);
    n2 = ntohl(n2);
    result = n1 + n2;

    // 결과 값 출력
    printf(" %d + %d = %d \n",n1,n2,result);
    printf(" 0x%x + 0x%x = 0x%x \n",n1,n2,result);
}

int main(int argc, char *argv[]) {
    // 인자 값 체크
    if (argc < 3){
        printf("syntax : %s <file1> <file2> \n", argv[0]);
        printf("sample : %s a.bin c.bin \n",argv[0]);
        return 0;
    }

    // 변수 선언
    FILE *fd1, *fd2;
    uint32_t n1,n2,result;

    fd1 = fopen(argv[1], "rb");
    if(fd1 == NULL){
        printf("I can't open this file!! PLZ Check :( \n");
        return 0;
    }
    fd2 = fopen(argv[2], "rb");
    if(fd1 == NULL){
        printf("I can't open this file!! :( \n");
        return 0;
    }

    fread(&n1, 1, 128, fd1);
    fread(&n2, 1, 128, fd2);

    fclose(fd2);
    fclose(fd1);

    add_fun(n1,n2,result);

    return 0;
}
