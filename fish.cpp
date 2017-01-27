#include "fish.h"

Fish::Fish(){

}

void Fish::draw(){
    glEnable(GL_TEXTURE_2D);
    GLuint texture=load_fish_texture();
    glBindTexture( GL_TEXTURE_2D, texture );
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3d(center_x,center_y,center_z-0.5);
    glVertex3d(center_x-2,center_y,center_z);
    glVertex3d(center_x,center_y-1,center_z);

    glVertex3d(center_x,center_y,center_z-0.5);
    glVertex3d(center_x-2,center_y,center_z);
    glVertex3d(center_x,center_y+1,center_z);

    glVertex3d(center_x,center_y,center_z-0.5);
    glVertex3d(center_x+3,center_y,center_z-0.3);
    glVertex3d(center_x,center_y-1,center_z);

    glVertex3d(center_x,center_y,center_z-0.5);
    glVertex3d(center_x+3,center_y,center_z-0.3);
    glVertex3d(center_x,center_y+1,center_z);

    glVertex3d(center_x,center_y,center_z+0.5);
    glVertex3d(center_x-2,center_y,center_z);
    glVertex3d(center_x,center_y-1,center_z);

    glVertex3d(center_x,center_y,center_z+0.5);
    glVertex3d(center_x-2,center_y,center_z);
    glVertex3d(center_x,center_y+1,center_z);

    glVertex3d(center_x,center_y,center_z+0.5);
    glVertex3d(center_x+3,center_y,center_z+0.3);
    glVertex3d(center_x,center_y-1,center_z);

    glVertex3d(center_x,center_y,center_z+0.5);
    glVertex3d(center_x+3,center_y,center_z+0.3);
    glVertex3d(center_x,center_y+1,center_z);

    glVertex3d(center_x,center_y+1,center_z);
    glVertex3d(center_x+3,center_y,center_z+0.3);
    glVertex3d(center_x+3,center_y,center_z-0.3);

    glVertex3d(center_x,center_y-1,center_z);
    glVertex3d(center_x+3,center_y,center_z+0.3);
    glVertex3d(center_x+3,center_y,center_z-0.3);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(center_x+2,center_y,center_z+0.3);
    glVertex3d(center_x+5,center_y+0.8,center_z+back_fin_z_move);
    glVertex3d(center_x+4.5,center_y,center_z+back_fin_z_move);
    glVertex3d(center_x+5,center_y-0.8,center_z+back_fin_z_move);

    glVertex3d(center_x+2,center_y,center_z-0.3);
    glVertex3d(center_x+5,center_y+0.8,center_z+back_fin_z_move);
    glVertex3d(center_x+4.5,center_y,center_z+back_fin_z_move);
    glVertex3d(center_x+5,center_y-0.8,center_z+back_fin_z_move);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3d(center_x+1.2,center_y-0.5,center_z-0.2);
    glVertex3d(center_x+1.5,center_y-0.5,center_z-0.2);
    glVertex3d(center_x+1,center_y-1+side_fins_y_move,center_z-0.4+side_fins_z_move);

    glVertex3d(center_x+1.2,center_y-0.5,center_z-0.1);
    glVertex3d(center_x+1.5,center_y-0.5,center_z-0.1);
    glVertex3d(center_x+1,center_y-1+side_fins_y_move,center_z-0.4+side_fins_z_move);

    glVertex3d(center_x+1.2,center_y-0.5,center_z-0.1);
    glVertex3d(center_x+1.2,center_y-0.5,center_z-0.2);
    glVertex3d(center_x+1,center_y-1+side_fins_y_move,center_z-0.4+side_fins_z_move);

    glVertex3d(center_x+1.2,center_y-0.5,center_z+0.1);
    glVertex3d(center_x+1.5,center_y-0.5,center_z+0.1);
    glVertex3d(center_x+1,center_y-1+side_fins_y_move,center_z+0.4+side_fins_z_move);

    glVertex3d(center_x+1.2,center_y-0.5,center_z+0.2);
    glVertex3d(center_x+1.5,center_y-0.5,center_z+0.2);
    glVertex3d(center_x+1,center_y-1+side_fins_y_move,center_z+0.4+side_fins_z_move);

    glVertex3d(center_x+1.2,center_y-0.5,center_z+0.1);
    glVertex3d(center_x+1.2,center_y-0.5,center_z+0.2);
    glVertex3d(center_x+1,center_y-1+side_fins_y_move,center_z+0.4+side_fins_z_move);
    glEnd();
}

GLuint Fish::load_fish_texture(){
    FIBITMAP * bitmap;
    FREE_IMAGE_FORMAT fif=FreeImage_GetFIFFromFilename("fish_texture.jpg");
    bitmap=FreeImage_Load(fif,"fish_texture.jpg",JPEG_DEFAULT);
    if (!bitmap){
        std::cerr<<"Could not load fish texture image"<<std::endl;
        exit(0);
    }
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
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,texels);
    free(texels);
    FreeImage_Unload(bitmap);
    return tex_id;
}
