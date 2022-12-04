#include<bits/stdc++.h>
using namespace std;

float average(vector<int>arr){
    int sum=0;
    int n=arr.size();
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    float avg=(float)sum/n;
    return avg;
}

float variance(vector<int>arr, int avg){
    int diff=0;
    int n=arr.size();
    float var=0;

    for(int i=0; i<n; i++){
        diff=abs(arr[i]-avg);
        var=(diff*diff)/n;
    }
    float res=(float)var/n;
    return res;
}

float deviation(vector<int>arr, int avg){
    int diff=0;
    int n=arr.size();
    float var=0;

    for(int i=0; i<n; i++){
        diff=abs(arr[i]-avg);
        var=(diff*diff)/n;
    }
    float res=(float)var/n;
    return sqrt(res);
}

vector<int> gradient(vector<int>arr){
    int n=arr.size();
    vector<int>grad(n-1);
    for(int i=0; i<n-1; i++){
        grad[i]=arr[i+1]-arr[i];
    }
    return grad;

}

vector<int> laplacian(vector<int>grad){
    int n=grad.size();
    vector<int>laplace(n-1);
    for(int i=0; i<n-1; i++){
        laplace[i]=grad[i+1]-grad[i];
    }
    return laplace;
}

void smoothening(vector<int>arr){
    vector<int>filter(5,1);
    int n=arr.size();
    vector<float>arr2(n+4);
    arr2[0]=(float)arr[1];
    arr2[1]=(float)arr[2];

    for(int i=0; i<n; i++){
        arr2[i+2]=(float)arr[i];
    }

    arr2[n+2]=(float)arr[n-2];
    arr2[n+3]=(float)arr[n-3];

    vector<float>res=arr2;
    int j=2;
    for(int i=0; i<n; i++){
        res[i]=(arr2[j-2]+arr2[j-1]+arr2[j]+arr2[j+1]+arr2[j+2])/5;
        j++;
    }

    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void movAvg(vector<int>arr, float beta){
    int n=arr.size();
    vector<float>V(n);
    V[0]=0;
    
    for(int i=1; i<n; i++){
        V[i]=beta*(float)arr[i]+(1-beta)*V[i-1];
        cout<<V[i]<<" ";
    }
    cout<<endl;
}

void normal(vector<int>arr){
    int n=arr.size();
    int mean=average(arr);
    int min=arr[0];
    int max=arr[n-1];
    int range=max-min;

    vector<float>normalized(n);
    for(int i=0; i<n; i++){
        normalized[i]=(float)(((float)arr[i]-mean)/range);
        cout<<normalized[i]<<" ";
    }

}

void adam(vector<int>arr, float alpha, float epsilon){
    vector<int>grad=gradient(arr);
    vector<int>laplace=laplacian(arr);
    
    int n=arr.size();
    vector<int>res(n);
    for(int i=0; i<n; i++){
        float a=(float)((float)arr[i]-alpha*(float)grad[i]);
        float b=epsilon+(float)sqrt(laplace[i]);
        res[i]=a/b;
        cout<<res[i]<< " ";
    }
}

int main(){
    vector<int>arr={0,2,1,22,2,1,3,5,9,15,8,10,10,11,10,14,20,25,27,58,78,69,94,74,86,73,153,136,120,187,309,424,486,560,579,609,484,573,565,813,871,854,758,1243,1031,886,1061,922,1371,1580,1239,1537,1292,1667,1408,1835,1607,1568,1902,1705,1801,2391};
    float avg=average(arr);
    cout<<"***********Q1***********"<<endl;
    cout<<"The Mean is "<<avg;
    cout<<endl;

    cout<<"The varince is "<<variance(arr,avg)<<endl;

    cout<<"***********Q2***********"<<endl;
    cout<<"Gradient:"<<endl;
    vector<int>grad=gradient(arr);
    for(int i=0; i<grad.size(); i++){
        cout<<grad[i]<<" ";
    }
    cout<<endl;

    cout<<"Laplacian"<<endl;
    vector<int>laplace=laplacian(arr);
    for(int i=0; i<laplace.size(); i++){
        cout<<laplace[i]<<" ";
    }
    cout<<endl;
    cout<<"***********Q3***********"<<endl;
    cout<<"The array after smoothening with an averaging filter is "<<endl;
    smoothening(arr);

    cout<<"***********Q4***********"<<endl;
    cout<<"The array with moving average applied at each data point and Beta is "<<endl;
    float beta=0.9;
    cout<<"Beta 0.9 "<<endl;
    movAvg(arr,beta);

    beta=0.7;
    cout<<"Beta 0.7 "<<endl;
    movAvg(arr,beta);

    beta=0.5;
    cout<<"Beta 0.5 "<<endl;
    movAvg(arr,beta);

    cout<<endl;
    cout<<"***********Q5***********"<<endl;
    cout<<"Normalized array is"<<endl;
    normal(arr);
    cout<<endl;

    cout<<"Using Adam Optimizer with alpha=0.1, epsilon=0.01"<<endl;
    adam(arr,0.1,0.01);
    
    cout<<endl;
}


/*
Results:
***********Q1***********
The Mean is 600.871
The varince is 834.452
***********Q2***********
Gradient:
2 -1 21 -20 -1 2 2 4 6 -7 2 0 1 -1 4 6 5 2 31 20 -9 25 -20 12 -13 80 -17 -16 67 122 115 62 74 19 30 -125 89 -8 248 58 -17 -96 485 -212 -145 175 -139 449 209 -341 298 -245 375 -259 427 -228 -39 334 -197 96 590 
Laplacian
2 -1 21 -20 -1 2 2 4 6 -7 2 0 1 -1 4 6 5 2 31 20 -9 25 -20 12 -13 80 -17 -16 67 122 115 62 74 19 30 -125 89 -8 248 58 -17 -96 485 -212 -145 175 -139 449 209 -341 298 -245 375 -259 427 -228 -39 334 -197 96 590 
***********Q3***********
The array after smoothening with an averaging filter is 
1.2 5.2 5.4 5.6 5.8 6.6 4 6.6 8 9.4 10.4 10.8 9.8 11 13 16 19.2 28.8 41.6 51.4 65.2 74.6 80.2 79.2 96 104.4 113.6 133.8 181 235.2 305.2 393.2 471.6 531.6 543.6 561 562 608.8 661.2 735.2 772.2 907.8 951.4 954.4 995.8 1028.6 1054.2 1164 1234.6 1329.8 1403.8 1463 1428.6 1547.8 1561.8 1617 1664 1723.4 1716.6 1873.4 1920 1880.6 
***********Q4***********
The array with moving average applied at each data point and Beta is
Beta 0.9
1.8 1.08 19.908 3.7908 1.27908 2.82791 4.78279 8.57828 14.3578 8.63578 9.86358 9.98636 10.8986 10.0899 13.609 19.3609 24.4361 26.7436 54.8744 75.6874 69.6687 91.5669 75.7567 84.9757 74.1976 145.12 136.912 121.691 180.469 296.147 411.215 478.521 551.852 576.285 605.729 496.173 565.317 565.032 788.203 862.72 854.872 767.687 1195.47 1047.45 902.145 1045.11 934.311 1327.33 1554.73 1270.57 1510.36 1313.84 1631.68 1430.37 1794.54 1625.75 1573.78 1869.18 1721.42 1793.04 2331.2
Beta 0.7
1.4 1.12 15.736 6.1208 2.53624 2.86087 4.35826 7.60748 12.7822 9.43467 9.8304 9.94912 10.6847 10.2054 12.8616 17.8585 22.8575 25.7573 48.3272 69.0982 69.0294 86.5088 77.7526 83.5258 76.1577 129.947 134.184 124.255 168.177 266.753 376.826 453.248 527.974 563.692 595.408 517.422 556.327 562.398 737.819 831.046 847.114 784.734 1105.52 1053.36 936.207 1023.56 952.469 1245.44 1479.63 1311.19 1469.26 1345.18 1570.45 1456.74 1721.52 1641.36 1590.01 1808.4 1736.02 1781.51 2208.15
Beta 0.5
1 1 11.5 6.75 3.875 3.4375 4.21875 6.60938 10.8047 9.40234 9.70117 9.85059 10.4253 10.2126 12.1063 16.0532 20.5266 23.7633 40.8816 59.4408 64.2204 79.1102 76.5551 81.2775 77.1388 115.069 125.535 122.767 154.884 231.942 327.971 406.985 483.493 531.246 570.123 527.062 550.031 557.515 685.258 778.129 816.064 787.032 1015.02 1023.01 954.504 1007.75 964.876 1167.94 1373.97 1306.48 1421.74 1356.87 1511.94 1459.97 
1647.48 1627.24 1597.62 1749.81 1727.41 1764.2 2077.6

***********Q5***********
Normalized array is
-0.250941 -0.250105 -0.250523 -0.24174 -0.250105 -0.250523 -0.249686 -0.24885 -0.247177 -0.244668 -0.247595 -0.246759 -0.246759 -0.24634 
-0.246759 -0.245086 -0.242576 -0.240485 -0.239649 -0.226683 -0.218319 -0.222083 -0.211627 -0.219992 -0.214973 -0.22041 -0.186951 -0.194061 -0.200753 -0.172731 -0.121706 -0.0736094 -0.0476788 -0.0167294 -0.00878294 0.00376412 -0.0485153 -0.0112923 -0.0146382 0.0890841 0.113342 0.106232 0.0660811 0.268925 0.180259 0.119615 0.192806 0.134672 0.322459 0.40987 0.267252 0.391886 0.289419 0.446257 0.337934 0.51652 
0.421163 0.404852 0.544542 0.46215 0.5023 0.749059
Using Adam Optimizer with alpha=0.1, epsilon=0.01
0 -2147483648 0 -2147483648 -2147483648 0 1 2 3 -2147483648 5 1000 9 -2147483648 4 5 8 17 4 12 -2147483648 13 -2147483648 20 -2147483648 
7 -2147483648 -2147483648 13 15 27 52 55 127 104 -2147483648 50 -2147483648 34 105 -2147483648 -2147483648 32 -2147483648 -2147483648 65 
-2147483648 41 93 -2147483648 70 -2147483648 64 -2147483648 66 -2147483648 -2147483648 83 -2147483648 172 71 0
*/
