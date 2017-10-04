// openGLphotodecoder.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl\glew.h>
#include <windows.h>

int main()
{
	GLuint m_ImgTexture;
	HBITMAP h_Bmp;
	BITMAP m_Bmp;

	glGenTextures(1, &m_ImgTexture);

	//GL_BGR;
	h_Bmp = (HBITMAP)LoadImage(GetModuleHandle(NULL), (LPCWSTR)"file.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION| LR_LOADFROMFILE);
	if (h_Bmp)return -1;

	GetObject(h_Bmp, sizeof(m_Bmp), &m_Bmp);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glBindTexture(GL_TEXTURE_2D, m_ImgTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, m_Bmp.bmWidth, m_Bmp.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_Bmp.bmBits);
	DeleteObject(h_Bmp);
    return 0;
}

