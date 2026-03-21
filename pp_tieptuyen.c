#include <stdio.h>
#include <math.h>
#define EPS 1e-6

float f0(float x){
    return exp(x) - 10*x + 7 ;
}

float df0(float x){
    return exp(x) - 10;
}

void nhap(float a[], int n){
    for(int i = 0; i <= n; i++){
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }
}

float f(float a[], int n, float x){
    float p= a[0];
    for(int i = 1; i <= n; i++)
        p = p*x + a[i];
    return p;
}

float df(float a[], int n, float x){
    float p = a[0]*n;
    for(int i = 1; i < n; i++)
        p = p*x + a[i]*(n - i);
    return p;
}

float tieptuyen_f0(float x0){
    float x = x0, y;
    do{
        y = x;
        x = y - f0(y)/df0(y);
    } while(fabs(x - y) >= EPS);
    return x;
}

float tieptuyen_f(float a[], int n, float x0){
    float x = x0, y;
    do{
        y = x;
        x = y - f(a,n,y)/df(a,n,y);
    } while(fabs(x - y) >= EPS);

    return x;
}

int main(){
    int choice;
    char tt;
    printf("1.Ham nguon\n");
    printf("2.Ham da thuc\n");
    printf("Chon: ");  scanf("%d", &choice);
    if(choice == 1){
        float x0;
        while(1){
            printf("\nNhap xap xi ban dau: ");
            scanf("%f",&x0);
            printf("Nghiem cua phuong trinh : %.6f\n", tieptuyen_f0(x0));
            printf("Ban muon tiep tuc khong ? (c/k): ");
           scanf(" %c", &tt);
            if(tt=='k'|| tt=='K') break;
        }
    }
    else{
        int n;
        float a[100], x0;
        printf("Nhap bac n: ");scanf("%d", &n);
        printf("Nhap he so tu bac cao den thap:\n");
        nhap(a, n);
        while(1){
            printf("\nNhap xap xi ban dau : "); scanf("%f", &x0);
            float nghiem=tieptuyen_f(a,n,x0);
            if(fabs(nghiem) < EPS) nghiem = 0;
            printf("Nghiem: %.6f\n", nghiem);
            printf("Ban muon tiep tuc khong ? (c/k): ");
            scanf(" %c", &tt);
            if(tt=='k'||tt=='K') break;
        }
    }
    return 0;
}
