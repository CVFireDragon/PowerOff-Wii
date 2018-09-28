//Power Off for the Nintendo Wii (with ascii art) by @CVFD_

#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>


//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

//---------------------------------------------------------------------------------

	

	VIDEO_Init();
	

	rmode = VIDEO_GetPreferredMode(NULL);


	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	

	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	

	VIDEO_Configure(rmode);
	

	VIDEO_SetNextFramebuffer(xfb);
	

	VIDEO_SetBlack(FALSE);


	VIDEO_Flush();


	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();


	VIDEO_Init();
	

	
	//--------------------------------------------------------------------------------
	
	printf("\x1b[2;0H");


	STM_ShutdownToStandby();



	return 0;
}

