/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

Notice: (C) Copyright 2025 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/

#pragma once

struct animation_information
{
    s32 frame_rate;
    
    asset_animation* animations[10];
    s32 animation_count;
};

internal void
animator_update(animation_information* animator, r32 frame_ms)
{
    for(s32 anim = 0; anim < animator->animation_count; anim++)
    {
	
	
    }
    
}

internal void
animator_play(animation_information* animator, asset_animation* animation)
{
    animator->animations[animator->animation_count] = animation;
}






