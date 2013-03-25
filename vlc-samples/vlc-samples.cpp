// vlc-samples.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vlc/vlc.h>
#include <Windows.h>

using namespace std;

void media_player_set_media(const char *path);
void wait_play_finished(libvlc_media_player_t *mp);

void media_player_set_media(const char *path)
{
    libvlc_instance_t *vlc = libvlc_new(0, NULL);
 
    libvlc_media_t *media = libvlc_media_new_path(vlc, path);

	libvlc_media_parse(media);
	char *str = 0;
	str = libvlc_media_get_meta(media, libvlc_meta_Title);
	str = libvlc_media_get_meta(media, libvlc_meta_Artist);
	str = libvlc_media_get_meta(media, libvlc_meta_Genre);
	str = libvlc_media_get_meta(media, libvlc_meta_Copyright);
	str = libvlc_media_get_meta(media, libvlc_meta_Album);
	str = libvlc_media_get_meta(media, libvlc_meta_TrackNumber);
	str = libvlc_media_get_meta(media, libvlc_meta_Description);
	str = libvlc_media_get_meta(media, libvlc_meta_Rating);
	str = libvlc_media_get_meta(media, libvlc_meta_Date);
	str = libvlc_media_get_meta(media, libvlc_meta_Setting);
	str = libvlc_media_get_meta(media, libvlc_meta_URL);
	str = libvlc_media_get_meta(media, libvlc_meta_Language);
	str = libvlc_media_get_meta(media, libvlc_meta_NowPlaying);
	str = libvlc_media_get_meta(media, libvlc_meta_Publisher);
	str = libvlc_media_get_meta(media, libvlc_meta_EncodedBy);
	str = libvlc_media_get_meta(media, libvlc_meta_ArtworkURL);
	str = libvlc_media_get_meta(media, libvlc_meta_TrackID);

//typedef enum libvlc_meta_t {
//    libvlc_meta_Title,
//    libvlc_meta_Artist,
//    libvlc_meta_Genre,
//    libvlc_meta_Copyright,
//    libvlc_meta_Album,
//    libvlc_meta_TrackNumber,
//    libvlc_meta_Description,
//    libvlc_meta_Rating,
//    libvlc_meta_Date,
//    libvlc_meta_Setting,
//    libvlc_meta_URL,
//    libvlc_meta_Language,
//    libvlc_meta_NowPlaying,
//    libvlc_meta_Publisher,
//    libvlc_meta_EncodedBy,
//    libvlc_meta_ArtworkURL,
//    libvlc_meta_TrackID
//    /* Add new meta types HERE */
//} libvlc_meta_t;

    libvlc_media_player_t *mp = libvlc_media_player_new_from_media(media);
    
	libvlc_media_release(media);

    libvlc_media_player_play(mp);

    wait_play_finished(mp);

    libvlc_media_player_stop(mp);
    libvlc_media_player_release(mp);
    libvlc_release(vlc);
}

void wait_play_finished(libvlc_media_player_t *mp)
{
    libvlc_state_t state;
    do {
		Sleep(100);
        state = libvlc_media_player_get_state(mp);
    } while(state != libvlc_Error &&
            state != libvlc_Ended );
}

int _tmain(int argc, _TCHAR* argv[])
{
	media_player_set_media("dvd:///D:/GitHub/vlc-samples/bin/vob#1:3");//VIDEO_TS.IFO VTS_01_0.IFO VTS_01_1.VOB

	return 0;
}

