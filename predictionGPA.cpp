#include <stdio.h>
#include <string.h>
#include <math.h>
char str[103];
double N, M, rating[6043][4003];
double calc_r(int movie, int recent){
	int i, cnt=0;
	double mx=0, my=0, r=0, sx=0, sy=0;
	for(i=1; i<=6040; i++){
		if(!rating[i][movie]||!rating[i][recent]) continue;
		mx+=rating[i][movie], my+=rating[i][recent];
		cnt++;
	}
	if(!cnt) return -1.00;
	mx/=cnt, my/=cnt;
	for(i=1; i<=6040; i++){
		if(!rating[i][movie]||!rating[i][recent]) continue;
		sx+=(rating[i][movie]-mx)*(rating[i][movie]-mx);
		sy+=(rating[i][recent]-my)*(rating[i][recent]-my);
	}
	sx=sqrt(sx), sy=sqrt(sy);
	for(i=1; i<=6040; i++){
		if(!rating[i][movie]||!rating[i][recent]) continue;
		r+=(rating[i][movie]-mx)/sx*(rating[i][recent]-my)/sy;
	}
	r/=(cnt-1);
	M=(sy/sx)*r;
	N=my-mx*M;
	return r;
}

int main(){
	//freopen("ratings.txt", "r", stdin); 
	int i, j, GPA, name=0, name_m=0, U, R;
	double w, r, wp, res=0, error, cnt=0;
	j=1;
	while(true){
		scanf("%s", str);
		if(str[0]=='0') break;
		i=0;
		
		while(true){
			if(str[i]==':') break;
			name=10*name+str[i]-'0';
			i++;
		}
		
		i+=2;
		
		while(true){
			if(str[i]==':') break;
			name_m=10*name_m+str[i]-'0';
			i++;
		}
		
		i+=2;
		rating[name][name_m]=str[i]-48;
		rating[name][name_m]=str[i]-48;
		j++;
		name=name_m=0;
	}
	while(true){
		scanf("%d %d", &U, &R);
		if(!U) break;
		r=w=wp=0;
		for(i=1; i<=4000; i++){
			if(!rating[U][i]) continue;
			r=calc_r(i, R);
			if(r<=0) continue;
			w+=r*r;
			wp+=r*r*(r*M*rating[U][i]+N);
		}
		wp/=w;
		error=rating[U][R]-wp;
		if(error<0) error*-1;
		res+=error;
		cnt++;
	}
	res/=cnt;
	printf("%.2lf", res);
	return 0;
} 
