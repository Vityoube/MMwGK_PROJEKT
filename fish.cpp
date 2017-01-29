#include "fish.h"

Fish::Fish(){

}

void Fish::draw(){
    glDisable(GL_DEPTH_TEST);
    GLfloat a=1,b=0.5,c=0.5;
    glBegin(GL_LINES);
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    for (GLfloat u=0.0f;u<=360.0f;u+=1)
        for(GLfloat v=0.0f;v<=360.0f;v+=1){
            GLfloat x=center_x+a*cos(u)*cos(v);
            GLfloat z_translation;
            if (x<-a/2)
                z_translation=0;
            else if (x>-a/2 && x<=a/2)
                z_translation=-back_fin_z_move;
            else if (x>a/2)
                z_translation=back_fin_z_move;

            GLfloat y=center_y+b*cos(u)*sin(v);
            if (x>2*a/3 && u<=180)
                y-=0.3;
            else if (x>2*a/3 && u>180)
                y+=0.3;
            GLfloat z=center_z+c*sin(u)+z_translation;
            glVertex3f(x,y,z);
        }
      glEnd();

      glBegin(GL_POLYGON);
      glVertex3d(center_x+a/2,center_y,center_z+0.1+back_fin_z_move/2);
      glVertex3d(center_x+a+1,center_y+b*2,center_z+0.1+back_fin_z_move);
      glVertex3d(center_x+a+0.5,center_y,center_z+0.1+back_fin_z_move);
      glVertex3d(center_x+a+1,center_y-b*2,center_z+0.1+back_fin_z_move);

      glVertex3d(center_x+a/2,center_y,center_z-0.1+back_fin_z_move/2);
      glVertex3d(center_x+a+1,center_y+b*2,center_z-0.1+back_fin_z_move);
      glVertex3d(center_x+a+0.5,center_y,center_z-0.1+back_fin_z_move);
      glVertex3d(center_x+a+1,center_y-b*2,center_z-0.1+back_fin_z_move);

      glVertex3d(center_x+a/2,center_y,center_z-0.1+back_fin_z_move/2);
      glVertex3d(center_x+a/2,center_y,center_z+0.1+back_fin_z_move/2);
      glVertex3d(center_x+a+1,center_y+b*2,center_z-0.1+back_fin_z_move);
      glVertex3d(center_x+a+1,center_y+b*2,center_z+0.1+back_fin_z_move);

      glVertex3d(center_x+a/2,center_y,center_z-0.1+back_fin_z_move/2);
      glVertex3d(center_x+a/2,center_y,center_z+0.1+back_fin_z_move/2);
      glVertex3d(center_x+a+1,center_y-b*2,center_z-0.1+back_fin_z_move);
      glVertex3d(center_x+a+1,center_y-b*2,center_z+0.1+back_fin_z_move);
      glEnd();

      glBegin(GL_TRIANGLES);
      glVertex3d(center_x-a/2,center_y+b-0.2,center_z+0.1-back_fin_z_move);
      glVertex3d(center_x+a/2,center_y+b-0.2,center_z+0.1-back_fin_z_move);
      glVertex3d(center_x+a,center_y+b*2,center_z+0.1-back_fin_z_move);

      glVertex3d(center_x-a/2,center_y+b-0.2,center_z-0.1-back_fin_z_move);
      glVertex3d(center_x+a/2,center_y+b-0.2,center_z-0.1-back_fin_z_move);
      glVertex3d(center_x+a,center_y+b*2,center_z-0.1-back_fin_z_move);

      glEnd();
      glBegin(GL_QUADS);
      glVertex3d(center_x-a/2,center_y+b-0.2,center_z-0.1-back_fin_z_move);
      glVertex3d(center_x-a/2,center_y+b-0.2,center_z+0.1-back_fin_z_move);
      glVertex3d(center_x+a,center_y+b*2,center_z-0.1-back_fin_z_move);
      glVertex3d(center_x+a,center_y+b*2,center_z+0.1-back_fin_z_move);

      glVertex3d(center_x+a/2,center_y+b-0.2,center_z-0.1-back_fin_z_move);
      glVertex3d(center_x+a/2,center_y+b-0.2,center_z+0.1-back_fin_z_move);
      glVertex3d(center_x+a,center_y+b*2,center_z-0.1-back_fin_z_move);
      glVertex3d(center_x+a,center_y+b*2,center_z+0.1-back_fin_z_move);
      glEnd();

      glBegin(GL_TRIANGLES);
      glVertex3d(center_x+a/3,center_y-b+0.2,center_z+c/2-0.3+back_fin_z_move);
      glVertex3d(center_x+(2*a/3),center_y-b+0.2,center_z+c/2-0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.15,center_z+c+0.2+back_fin_z_move);

      glVertex3d(center_x+a/3,center_y-b+0.1,center_z+c/2-0.3+back_fin_z_move);
      glVertex3d(center_x+(2*a/3),center_y-b+0.1,center_z+c/2-0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.15,center_z+c+0.2+back_fin_z_move);

      glVertex3d(center_x+a/3,center_y-b+0.1,center_z+c/2-0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.2,center_z+c/2-0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.15,center_z+c+0.2+back_fin_z_move);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex3d(center_x+a/3,center_y-b+0.2,center_z-c/2+0.3+back_fin_z_move);
      glVertex3d(center_x+(2*a/3),center_y-b+0.2,center_z-c/2+0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.15,center_z-c-0.2+back_fin_z_move);

      glVertex3d(center_x+a/3,center_y-b+0.1,center_z-c/2+0.3+back_fin_z_move);
      glVertex3d(center_x+(2*a/3),center_y-b+0.1,center_z-c/2+0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.15,center_z-c-0.2+back_fin_z_move);

      glVertex3d(center_x+a/3,center_y-b+0.1,center_z-c/2+0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.2,center_z-c/2+0.3+back_fin_z_move);
      glVertex3d(center_x+a/3,center_y-b+0.15,center_z-c-0.2+back_fin_z_move);
      glEnd();
}

GLuint Fish::load_fish_texture(FIBITMAP * bitmap){

    GLuint tex_id=0;
    int x=0, y=0;
    int height,width;
    RGBQUAD rgbquad;
    FREE_IMAGE_TYPE image_type;
    BITMAPINFOHEADER * header;
    image_type=FreeImage_GetImageType(bitmap);
    height=FreeImage_GetHeight(bitmap);
    width=FreeImage_GetWidth(bitmap);
    header=FreeImage_GetInfoHeader(bitmap);
    int scanLineWidth=((3*width)%4 == 0) ? 3*width : ((3*width/4)*4)+4;
    unsigned char * texels=(GLubyte*)calloc(height*scanLineWidth,sizeof(GLubyte));
    for (x=0;x<width;x++)
        for (y=0;y<height;y++){
            FreeImage_GetPixelColor(bitmap,x,y,&rgbquad);
            texels[y*scanLineWidth+3*x]=((GLbyte*)&rgbquad)[2];
            texels[y*scanLineWidth+3*x+1]=((GLbyte*)&rgbquad)[1];
            texels[y*scanLineWidth+3*x+2]=((GLbyte*)&rgbquad)[0];
        }
    glGenTextures(1,&tex_id);
    glBindTexture(GL_TEXTURE_2D,tex_id);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,texels);
    free(texels);
    FreeImage_Unload(bitmap);
    return tex_id;
}
