#include <stdio.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include "Define.h"
#include "prototype.h"

/*
	画像に直線や曲線を書き込む
*/

//画像に直線を縦横描画する
//---------------------------------------------------------------  
//【関数名　】：DrawImageGrid  
//【処理概要】：srcに直線を描画し，格子を作成した画像をdstに出力する
//【引数　　】：src1		= 入力画像  
//			  ：dst			= 出力画像
//			　：size		= 格子のサイズ
//			　：zx			= x方向のずれ(微妙な位置のずれ合せ)
//			　：zy			= y方向のずれ
//【戻り値　】：なし  
//【備考　　】：特になし
//--------------------------------------------------------------- 
void DrawImageGrid(IplImage *src, IplImage *dst , int size , int zx, int zy ){
	
	//画像の中心座標を求める
	int center_x,center_y;
	center_x = src->width/2;
	center_y = src->height/2;

	//cvCopy(src,dst);

	//画像の中心に縦横の赤いラインを引く
	cvLine(src,cvPoint(center_x+zx , 0), cvPoint(center_x+zx   ,src->height), CV_RGB(255,0,0) ,1);//縦線
	cvLine(src,cvPoint(0		, center_y+zy)   , cvPoint(src->width , center_y+zy), CV_RGB(255,0,0) ,1);//横線

	//printf("x = %d\n" , center_x);
	//printf("y = %d\n\n" , center_y);

	//縦方向に直線を引く()
	//中心から右方向に縦線を引く
	for( int x = center_x + size + zx; x < src->width; x+=size ){
		cvLine(src,cvPoint( x,  0), cvPoint(   x, src->height), CV_RGB(255,0,0) ,1);//縦線
		//printf("x = %d\n" , x);
	}
	//中心から左方向に縦線を引く
	for( int x = center_x - size + zx; x > 0; x-=size ){
		cvLine(src,cvPoint( x,  0), cvPoint( x, src->height), CV_RGB(255,0,0) ,  1);//縦線
		//printf("x = %d\n" , x);
	}
	//中心から下方向に横線を引く
	for( int y = center_y + size + zy; y < src->height; y+=size ){
		cvLine(src,cvPoint( 0,  y), cvPoint( src->width, y), CV_RGB(255,0,0) ,   1);//横線
		//printf("y = %d\n" , y);
	}
	//中心から上方向に横線を引く
	for( int y = center_y - size + zy; y > 0; y-=size ){
		cvLine(src,cvPoint( 0,  y), cvPoint( src->width, y), CV_RGB(255,0,0) ,   1);//横線
		//printf("y = %d\n" , y);
	}
}
//---------------------------------------------------------------  
//【関数名　】：DrawImageGrid  
//【処理概要】：周辺画素値を黒画素で塗りつぶす
//【引数　　】：src	= 入力画像  
//【戻り値　】：なし  
//【備考　　】：
//--------------------------------------------------------------- 
void DrawBlackImage( IplImage *src ){
	for( int i = 0; i < 3; i++ ){
		for( int x = 0; x < src->width; x++ ){
			for( int y = 0; y < src->height; y++ ){
				if(x >= 0 && y < src->height/4){
					IMAGE(src,x,y,i) = 0;
				}
				else if(x <= src->width / 4 && y < src->height / 4 * 3){
					IMAGE(src,x,y,i) = 0;
				}
				else if(x >= src->width / 4 * 3 && y < src->height / 4 * 3){
					IMAGE(src,x,y,i) = 0;
				}
				else if(x >= 0 && y >= src->height / 4 * 3){
					IMAGE(src,x,y,i) = 0;
				}
			}
		}
	}
}
