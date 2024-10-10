/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

 Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

// mem

internal inline void
mem_copy(void* source, void* destination, s32 size);
internal inline void
mem_clear(void* source, s32 size);

// i/o

struct io_file
{
    void* source;
    s32   size;
};

internal io_file
io_readfile(s8* filename);
internal void
io_writefile(s8* filename, s32 size, void* data);
internal void
io_freefile(io_file);



