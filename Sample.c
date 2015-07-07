#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int flagr=0;
int flagl=0;
void initimg (int iimg[][3], int ix, int iy){
int isize=ix*iy;
char fname[10]={0};
iimg[isize][3];
};
/*---------------*/
void fill (int fimg[][3], int fx,int fy, int fr, int fg, int fb){
int fsize=fx*fy;
int i;
for (i=0; i<fsize; i++){
	fimg[i][0]=fr;
	fimg[i][1]=fg;
	fimg[i][2]=fb;
	}
};
/*---------------*/
void showout (int simg[][3], int sx,int sy){
printf("P3\n");
printf("%d %d\n",sx,sy);
printf("255\n");
int j; int k=sx*sy;
for (j=0; j<k; j++){
	printf("%d %d %d\n",simg[j][0],simg[j][1],simg[j][2],j);
}
};
/*---------------*/
void writeout (char imgname[],int simg[][3], int sx,int sy){
FILE *wfile;
wfile =fopen((imgname),"w");

fputs("P3\n",wfile);
char sizestr[10]={0};
sprintf(sizestr,"%d %d\n",sx,sy);
fputs(sizestr,wfile);
fputs("255\n",wfile);
int j; int k=sx*sy;
char tmpstr[13]={0};
for (j=0; j<k; j++){
	sprintf(tmpstr,"%d %d %d\n",simg[j][0],simg[j][1],simg[j][2],j);
	fputs(tmpstr,wfile);
	
}

fclose(wfile);
};


/*-----------------------------------------------------------*/


void drawhorline (int dhimg[][3], int dhx, int dhy, int line,int dhr,int dhg, int dhb){
int dlx;
for (dlx=dhx*(line-1); dlx<dhx*line; dlx++){
	dhimg[dlx][0]=dhr;
	dhimg[dlx][1]=dhg;
	dhimg[dlx][2]=dhb;
}
};
/*---------------*/
void drawvertline (int dvimg[][3],int dvx, int dvy, int column,int dvr,int dvg, int dvb){
int dcy;
for (dcy=column-1; dcy<dvx*dvy; dcy+=dvx){
	dvimg[dcy][0]=dvr;
	dvimg[dcy][1]=dvg;
	dvimg[dcy][2]=dvb;
}
};


/*-----------------------------------------------------------*/



void turnleft (int trimg[][3],int trx, int try){
if (trx=try) flagr=0;
else flagr=1;
int ra,rb,rc;
int trxy = trx*try;
int tempr[trxy][3];

for (rb=-1, rc=trx+(trx*(try-1)); rb<trxy; rb++, rc-=trx){
	if (rc<0) {rc+=trxy+1;};
	if (rc==0) {rc=0;};
	tempr[rc][0]=trimg[rb][0];
	tempr[rc][1]=trimg[rb][1];
	tempr[rc][2]=trimg[rb][2];
}


int rd;
for (rd=0; rd<(trxy); rd++){
	trimg[rd][0]=tempr[rd][0];
	trimg[rd][1]=tempr[rd][1];
	trimg[rd][2]=tempr[rd][2];
}
} 


/*---------------*/


void turnright (int trimg[][3],int trx, int try){
if (trx=try) flagr=0;
else flagr=1;
int x3;
for (x3=0;x3<3;x3++){

int ra,rb,rc;
int trxy = trx*try;
int tempr[trxy][3];
for (rb=-1, rc=trx+(trx*(try-1)); rb<trxy; rb++, rc-=trx){
	if (rc<0) {rc+=trxy+1;};
	if (rc==0) {rc=0;};
	tempr[rc][0]=trimg[rb][0];
	tempr[rc][1]=trimg[rb][1];
	tempr[rc][2]=trimg[rb][2];
}


int rd;
for (rd=0; rd<(trxy); rd++){
	trimg[rd][0]=tempr[rd][0];
	trimg[rd][1]=tempr[rd][1];
	trimg[rd][2]=tempr[rd][2];
}

}

} 



/*------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------*/


int main(int argc, char *argv[])
{
/*image values*/
int x,y,size;
int image[100][3]={0};


/*redact values*/
int line,column;
int RF,GF,BF;
int R,G,B;
char clR[5]={0};
char clG[5]={0};
char clB[5]={0};
char fname[10]={0};

int exit=0;
int exit_r=0;
int le;

/* mm - main menu
   rm - redact menu
   lm - line menu   */
char mm[1]={0}; 
char rm[1]={0};
char lm[1]={0};

do {
printf("\n---Main menu---\n");
printf("n - new file\n");
printf("o - open file\n");
printf("e - exit\n");
scanf("%s",mm);
switch(mm[0]){
case 'n':
	printf("\n---Create new image---\n");
	printf("Usage: [x] [y]\n");
	char vvx[12]={0};
	char vvy[12]={0};
	scanf("%s %s",vvx,vvy);
	x=atoi(vvx);
	y=atoi(vvy);

	//printf("x=%d,y=%d.",x,y);

	printf("\n");

	/*|------------------------------------------------------------------*/
	/*|-------  "redact":  ----------------------------------------------*/
	/*|------------------------------------------------------------------*/
	/*|*/do {
	/*|*/printf("\n---Edit image---\n");
	/*|*/printf("f - fill image\n");
	/*|*/printf("h - add horisontal line\n");
	/*|*/printf("v - add vertical line\n");
	/*|*/printf("l - turn image left\n");
	/*|*/printf("r - turn image right\n");
	/*|*/printf("m - show image matrix\n");
	/*|*/printf("s - save image to file\n");
	/*|*/printf("b - discard changes and back to main menu\n");
	/*|*/
	/*|*/scanf("%s",rm);
	/*|*/switch (rm[0]){
	/*|*/case 'f':
	/*|*/	printf("\n---Fill image---\n");
	/*|*/	printf("Usage: [Red] [Green] [Blue]\n");
	/*|*/
	/*|*/	char clR[5]={0};
	/*|*/	char clG[5]={0};
	/*|*/	char clB[5]={0};
	/*|*/
	/*|*/	scanf("%s %s %s",clR,clG,clB);
	/*|*/
	/*|*/	RF=atoi(clR);
	/*|*/	GF=atoi(clG);
	/*|*/	BF=atoi(clB);
	/*|*/
	/*|*/	printf("R=%d,G=%d,B=%d\n",RF,GF,BF);
	/*|*/
	/*|*/	fill(image,x,y,RF,GF,BF);
	/*|*/break;
	/*|*/case 'h':
	/*|*/	printf("\n---Draw horizontal line ---\n");
	/*|*/	printf("Usage: [line] [Red] [Green] [Blue]\n");
	/*|*/	le=0;
	/*|*/	do{
	/*|*/		char lnn[5]={0};
	/*|*/		scanf("%s %s %s %s",lnn,clR,clG,clB);
	/*|*/		line=atoi(lnn);
	/*|*/		R=atoi(clR);
	/*|*/		G=atoi(clG);
	/*|*/		B=atoi(clB);
	/*|*/		
	/*|*/		drawhorline (image,x,y,line,R,G,B);
	/*|*/		
	/*|*/		printf("Add one more? (y/n): ");
	/*|*/		scanf("%s",lm);
	/*|*/		if (lm[0]!='y') le=1;
	/*|*/	} while (le==0);
	/*|*/break;
	/*|*/case 'v':
	/*|*/	printf("\n---Draw vertical line ---\n");
	/*|*/	printf("Usage: [column] [Red] [Green] [Blue]\n");
	/*|*/	le=0;
	/*|*/	do{
	/*|*/		char cln[5]={0};
	/*|*/		scanf("%s %s %s %s",cln,clR,clG,clB);
	/*|*/		column=atoi(cln);
	/*|*/		R=atoi(clR);
	/*|*/		G=atoi(clG);
	/*|*/		B=atoi(clB);
	/*|*/		
	/*|*/		drawvertline (image,x,y,column,R,G,B);
	/*|*/		
	/*|*/		printf("Add one more? (y/n): ");
	/*|*/		scanf("%s",lm);
	/*|*/		if (lm[0]!='y') le=1;
	/*|*/	} while (le==0);
	/*|*/break;
	/*|*/case 'l':
	/*|*/	printf("\n---Turn image left---\n");
	/*|*/	turnleft(image,x,y);
	/*|*/	printf("Turning image... Ok!\n");
	/*|*/break;
	/*|*/case 'r':
	/*|*/	printf("\n---Turn image right---\n");
	/*|*/	turnright(image,x,y);
	/*|*/	printf("Turning image... Ok!\n");
	/*|*/break;
	/*|*/case 'm':
	/*|*/	printf("\n---Show image matrix---\n");
	/*|*/	showout(image,x,y);
	/*|*/	printf("\n");
	/*|*/break;
	/*|*/
	/*|*/
	/*|*/case 's':
	/*|*/	printf("\n---Save image to file---\n");
	/*|*/	printf("File name: ***.pbm\n");
	/*|*/	scanf("%s",fname);
	/*|*/	writeout(fname,image,x,y);
	/*|*/break;
	/*|*/
	/*|*/
	/*|*/case 'b':
	/*|*/	exit_r=1;
	/*|*/break;
	/*|*/}
	/*|*/} while (exit_r==0);
	/*|------------------------------------------------------------------*/
	/*|-------  end of "redact"  ----------------------------------------*/
	/*|------------------------------------------------------------------*/

break;
/*-----*/
case 'o':
	printf("\n---Open image---\n");
	printf("File adress: ");
	char fladr[255]={0};
	scanf("%s",fladr);



	FILE *ofile;
	ofile =fopen(fladr,"r");
	
	char P3[2]={0};
	fscanf(ofile,"%s",P3);

	char rx[5]={0};
	char ry[5]={0};
	fscanf(ofile,"%s %s",rx,ry);
	x=atoi(rx);
	y=atoi(ry);
	size=x*y;

	char mxclr[3]={0};
	fscanf(ofile,"%s",mxclr);

	int j;
	char readred[5]={0};
	char readgrn[5]={0};
	char readblu[5]={0};
	for (j=0; j<size; j++){
		fscanf(ofile,"%s %s %s",readred,readgrn,readblu);
		
		image[j][0]=atoi(readred);
		image[j][1]=atoi(readgrn);
		image[j][2]=atoi(readblu);
	
	}
	
	fclose(ofile);

	printf("\n");
	
	/*|------------------------------------------------------------------*/
	/*|-------  "redact":  ----------------------------------------------*/
	/*|------------------------------------------------------------------*/
	/*|*/do {
	/*|*/printf("\n---Edit image---\n");
	/*|*/printf("f - fill image\n");
	/*|*/printf("h - add horisontal line\n");
	/*|*/printf("v - add vertical line\n");
	/*|*/printf("l - turn image left\n");
	/*|*/printf("r - turn image right\n");
	/*|*/printf("m - show image matrix\n");
	/*|*/printf("s - save image to file\n");
	/*|*/printf("b - discard changes and back to main menu\n");
	/*|*/
	/*|*/scanf("%s",rm);
	/*|*/switch (rm[0]){
	/*|*/case 'f':
	/*|*/	printf("\n---Fill image---\n");
	/*|*/	printf("Usage: [Red] [Green] [Blue]\n");
	/*|*/
	/*|*/	char clR[5]={0};
	/*|*/	char clG[5]={0};
	/*|*/	char clB[5]={0};
	/*|*/
	/*|*/	scanf("%s %s %s",clR,clG,clB);
	/*|*/
	/*|*/	RF=atoi(clR);
	/*|*/	GF=atoi(clG);
	/*|*/	BF=atoi(clB);
	/*|*/
	/*|*/	printf("R=%d,G=%d,B=%d\n",RF,GF,BF);
	/*|*/
	/*|*/	fill(image,x,y,RF,GF,BF);
	/*|*/break;
	/*|*/case 'h':
	/*|*/	printf("\n---Draw horizontal line ---\n");
	/*|*/	printf("Usage: [line] [Red] [Green] [Blue]\n");
	/*|*/	le=0;
	/*|*/	do{
	/*|*/		//vvod:
	/*|*/		char lnn[5]={0};
	/*|*/		scanf("%s %s %s %s",lnn,clR,clG,clB);
	/*|*/		line=atoi(lnn);
	/*|*/		R=atoi(clR);
	/*|*/		G=atoi(clG);
	/*|*/		B=atoi(clB);
	/*|*/		
	/*|*/		drawhorline (image,x,y,line,R,G,B);
	/*|*/		
	/*|*/		printf("Add one more? (y/n): ");
	/*|*/		scanf("%s",lm);
	/*|*/		if (lm[0]!='y') le=1;
	/*|*/	} while (le==0);
	/*|*/break;
	/*|*/case 'v':
	/*|*/	printf("\n---Draw vertical line ---\n");
	/*|*/	printf("Usage: [column] [Red] [Green] [Blue]\n");
	/*|*/	le=0;
	/*|*/	do{
	/*|*/		char cln[5]={0};
	/*|*/		scanf("%s %s %s %s",cln,clR,clG,clB);
	/*|*/		column=atoi(cln);
	/*|*/		R=atoi(clR);
	/*|*/		G=atoi(clG);
	/*|*/		B=atoi(clB);
	/*|*/		
	/*|*/		drawvertline (image,x,y,column,R,G,B);
	/*|*/		
	/*|*/		printf("Add one more? (y/n): ");
	/*|*/		scanf("%s",lm);
	/*|*/		if (lm[0]!='y') le=1;
	/*|*/	} while (le==0);
	/*|*/break;
	/*|*/case 'l':
	/*|*/	printf("\n---Turn image left---\n");
	/*|*/	turnleft(image,x,y);
	/*|*/	printf("Turning image... Ok!\n");
	/*|*/break;
	/*|*/case 'r':
	/*|*/	printf("\n---Turn image right---\n");
	/*|*/	turnright(image,x,y);
	/*|*/	printf("Turning image... Ok!\n");
	/*|*/break;
	/*|*/case 'm':
	/*|*/	printf("\n---Show image matrix---\n");
	/*|*/	showout(image,x,y);
	/*|*/	printf("\n");
	/*|*/break;
	/*|*/
	/*|*/
	/*|*/case 's':
	/*|*/	printf("\n---Save image to file---\n");
	/*|*/	printf("File name: ***.pbm\n");
	/*|*/	scanf("%s",fname);
	/*|*/	writeout(fname,image,x,y);
	/*|*/break;
	/*|*/
	/*|*/
	/*|*/case 'b':
	/*|*/	exit_r=1;
	/*|*/break;
	/*|*/}
	/*|*/} while (exit_r==0);
	/*|------------------------------------------------------------------*/
	/*|-------  end of "redact"  ----------------------------------------*/
	/*|------------------------------------------------------------------*/
break;
/*-----*/
case 'e': exit=1; break;
}

} while (exit == 0);


printf("\n-----About-----\n");
printf("Simple PBM redactor v.1.3\n");
printf("\t\tby AngelDLM08\n");
printf("angeldlm08@gmail.com\n");
printf("Moscow, 2014\n\n");

return 0;
}
