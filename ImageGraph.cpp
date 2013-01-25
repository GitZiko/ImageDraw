#include <stdio.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include "Define.h"
#include "prototype.h"

/*
	�摜�ɒ�����Ȑ�����������
*/

//�摜�ɒ������c���`�悷��
//---------------------------------------------------------------  
//�y�֐����@�z�FDrawImageGrid  
//�y�����T�v�z�Fsrc�ɒ�����`�悵�C�i�q���쐬�����摜��dst�ɏo�͂���
//�y�����@�@�z�Fsrc1		= ���͉摜  
//			  �Fdst			= �o�͉摜
//			�@�Fsize		= �i�q�̃T�C�Y
//			�@�Fzx			= x�����̂���(�����Ȉʒu�̂��ꍇ��)
//			�@�Fzy			= y�����̂���
//�y�߂�l�@�z�F�Ȃ�  
//�y���l�@�@�z�F���ɂȂ�
//--------------------------------------------------------------- 
void DrawImageGrid(IplImage *src, IplImage *dst , int size , int zx, int zy ){
	
	//�摜�̒��S���W�����߂�
	int center_x,center_y;
	center_x = src->width/2;
	center_y = src->height/2;

	//cvCopy(src,dst);

	//�摜�̒��S�ɏc���̐Ԃ����C��������
	cvLine(src,cvPoint(center_x+zx , 0), cvPoint(center_x+zx   ,src->height), CV_RGB(255,0,0) ,1);//�c��
	cvLine(src,cvPoint(0		, center_y+zy)   , cvPoint(src->width , center_y+zy), CV_RGB(255,0,0) ,1);//����

	//printf("x = %d\n" , center_x);
	//printf("y = %d\n\n" , center_y);

	//�c�����ɒ���������()
	//���S����E�����ɏc��������
	for( int x = center_x + size + zx; x < src->width; x+=size ){
		cvLine(src,cvPoint( x,  0), cvPoint(   x, src->height), CV_RGB(255,0,0) ,1);//�c��
		//printf("x = %d\n" , x);
	}
	//���S���獶�����ɏc��������
	for( int x = center_x - size + zx; x > 0; x-=size ){
		cvLine(src,cvPoint( x,  0), cvPoint( x, src->height), CV_RGB(255,0,0) ,  1);//�c��
		//printf("x = %d\n" , x);
	}
	//���S���牺�����ɉ���������
	for( int y = center_y + size + zy; y < src->height; y+=size ){
		cvLine(src,cvPoint( 0,  y), cvPoint( src->width, y), CV_RGB(255,0,0) ,   1);//����
		//printf("y = %d\n" , y);
	}
	//���S���������ɉ���������
	for( int y = center_y - size + zy; y > 0; y-=size ){
		cvLine(src,cvPoint( 0,  y), cvPoint( src->width, y), CV_RGB(255,0,0) ,   1);//����
		//printf("y = %d\n" , y);
	}
}
//---------------------------------------------------------------  
//�y�֐����@�z�FDrawImageGrid  
//�y�����T�v�z�F���Ӊ�f�l������f�œh��Ԃ�
//�y�����@�@�z�Fsrc	= ���͉摜  
//�y�߂�l�@�z�F�Ȃ�  
//�y���l�@�@�z�F
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
