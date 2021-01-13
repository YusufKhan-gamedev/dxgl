// DXGL
// Copyright (C) 2011-2021 William Feely

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once
#ifndef _GLDIRECTDRAWSURFACE_H
#define _GLDIRECTDRAWSURFACE_H

typedef struct
{
	bool enabled;
	bool colorspace;
	DDCOLORKEY key;
} CKEY;

struct glDirectDraw7;
struct glDirectDrawClipper;
struct glDirectDrawPalette;
struct glDirectDrawSurface1;
class glDirectDrawSurface2;
class glDirectDrawSurface3;
class glDirectDrawSurface4;
struct glDirect3DTexture2;
struct glDirect3DTexture1;
struct glDirect3DDevice7;
struct glDirectDrawGammaControl;

struct glDirectDrawSurface7Vtbl;
typedef struct glDirectDrawSurface7
{
	glDirectDrawSurface7Vtbl *lpVtbl;
	glDirectDrawSurface1 *dds1;
	glDirectDrawSurface2 *dds2;
	glDirectDrawSurface3 *dds3;
	glDirectDrawSurface4 *dds4;
	glDirect3DTexture2 *d3dt2;
	glDirect3DTexture1 *d3dt1;
	glDirectDrawGammaControl *gammacontrol;
	DWORD flipcount;
	DWORD fakex, fakey;
	float mulx, muly;
	CKEY colorkey[4];
	glTexture *texture;
	bool hasstencil;
	DWORD miplevel;
	DDSURFACEDESC2 ddsd;
	glDirectDrawPalette *palette;
	HGLRC hRC;
	D3DMATERIALHANDLE handle;
	glDirectDrawClipper *clipper;
	IUnknown *creator;
	IUnknown *textureparent;
	glDirectDrawSurface7 *zbuffer;
	glDirectDrawSurface7 *miptexture;
	glDirectDrawSurface7 *backbuffer;
	glDirectDrawSurface7 *backbufferwraparound;
	DWORD attachcount;
	glDirectDrawSurface7 *attachparent;
	BOOL overlayenabled;
	BOOL overlayset;
	int overlaycount;
	int maxoverlays;
	OVERLAY *overlays;
	glDirectDrawSurface7 *overlaydest;
	POINT overlaypos;
	int swapinterval;
	ULONG refcount7, refcount4, refcount3, refcount2, refcount1;
	ULONG refcountgamma, refcountcolor;
	int locked;
	glDirectDraw7 *ddInterface;
	//int surfacetype;  // 0-generic memory, 1-GDI surface, 2-OpenGL Texture
	int pagelocked;
	glDirect3DDevice7 *device1;
	glDirect3DDevice7 *device;
	IUnknown *zbuffer_iface;
	int version;
	unsigned char *clientbuffer;
} glDirectDrawSurface7;

typedef struct glDirectDrawSurface7Vtbl
{
	HRESULT(WINAPI *QueryInterface)(glDirectDrawSurface7 *This, REFIID riid, void** ppvObj);
	ULONG(WINAPI *AddRef)(glDirectDrawSurface7 *This);
	ULONG(WINAPI *Release)(glDirectDrawSurface7 *This);
	HRESULT(WINAPI *AddAttachedSurface)(glDirectDrawSurface7 *This, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface);
	HRESULT(WINAPI *AddOverlayDirtyRect)(glDirectDrawSurface7 *This, LPRECT lpRect);
	HRESULT(WINAPI *Blt)(glDirectDrawSurface7 *This, LPRECT lpDestRect, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
	HRESULT(WINAPI *BltBatch)(glDirectDrawSurface7 *This, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
	HRESULT(WINAPI *BltFast)(glDirectDrawSurface7 *This, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
	HRESULT(WINAPI *DeleteAttachedSurface)(glDirectDrawSurface7 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface);
	HRESULT(WINAPI *EnumAttachedSurfaces)(glDirectDrawSurface7 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpEnumSurfacesCallback);
	HRESULT(WINAPI *EnumOverlayZOrders)(glDirectDrawSurface7 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpfnCallback);
	HRESULT(WINAPI *Flip)(glDirectDrawSurface7 *This, LPDIRECTDRAWSURFACE7 lpDDSurfaceTargetOverride, DWORD dwFlags);
	HRESULT(WINAPI *GetAttachedSurface)(glDirectDrawSurface7 *This, LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE7 FAR *lplpDDAttachedSurface);
	HRESULT(WINAPI *GetBltStatus)(glDirectDrawSurface7 *This, DWORD dwFlags);
	HRESULT(WINAPI *GetCaps)(glDirectDrawSurface7 *This, LPDDSCAPS2 lpDDSCaps);
	HRESULT(WINAPI *GetClipper)(glDirectDrawSurface7 *This, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
	HRESULT(WINAPI *GetColorKey)(glDirectDrawSurface7 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT(WINAPI *GetDC)(glDirectDrawSurface7 *This, HDC FAR *lphDC);
	HRESULT(WINAPI *GetFlipStatus)(glDirectDrawSurface7 *This, DWORD dwFlags);
	HRESULT(WINAPI *GetOverlayPosition)(glDirectDrawSurface7 *This, LPLONG lplX, LPLONG lplY);
	HRESULT(WINAPI *GetPalette)(glDirectDrawSurface7 *This, LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
	HRESULT(WINAPI *GetPixelFormat)(glDirectDrawSurface7 *This, LPDDPIXELFORMAT lpDDPixelFormat);
	HRESULT(WINAPI *GetSurfaceDesc)(glDirectDrawSurface7 *This, LPDDSURFACEDESC2 lpDDSurfaceDesc);
	HRESULT(WINAPI *Initialize)(glDirectDrawSurface7 *This, LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc);
	HRESULT(WINAPI *IsLost)(glDirectDrawSurface7 *This);
	HRESULT(WINAPI *Lock)(glDirectDrawSurface7 *This, LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
	HRESULT(WINAPI *ReleaseDC)(glDirectDrawSurface7 *This, HDC hDC);
	HRESULT(WINAPI *Restore)(glDirectDrawSurface7 *This);
	HRESULT(WINAPI *SetClipper)(glDirectDrawSurface7 *This, LPDIRECTDRAWCLIPPER lpDDClipper);
	HRESULT(WINAPI *SetColorKey)(glDirectDrawSurface7 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT(WINAPI *SetOverlayPosition)(glDirectDrawSurface7 *This, LONG lX, LONG lY);
	HRESULT(WINAPI *SetPalette)(glDirectDrawSurface7 *This, LPDIRECTDRAWPALETTE lpDDPalette);
	HRESULT(WINAPI *Unlock)(glDirectDrawSurface7 *This, LPRECT lpRect);
	HRESULT(WINAPI *UpdateOverlay)(glDirectDrawSurface7 *This, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE7 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
	HRESULT(WINAPI *UpdateOverlayDisplay)(glDirectDrawSurface7 *This, DWORD dwFlags);
	HRESULT(WINAPI *UpdateOverlayZOrder)(glDirectDrawSurface7 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSReference);
	HRESULT(WINAPI *GetDDInterface)(glDirectDrawSurface7 *This, LPVOID FAR *lplpDD);
	HRESULT(WINAPI *PageLock)(glDirectDrawSurface7 *This, DWORD dwFlags);
	HRESULT(WINAPI *PageUnlock)(glDirectDrawSurface7 *This, DWORD dwFlags);
	HRESULT(WINAPI *SetSurfaceDesc)(glDirectDrawSurface7 *This, LPDDSURFACEDESC2 lpddsd2, DWORD dwFlags);
	HRESULT(WINAPI *SetPrivateData)(glDirectDrawSurface7 *This, REFGUID guidTag, LPVOID  lpData, DWORD   cbSize, DWORD   dwFlags);
	HRESULT(WINAPI *GetPrivateData)(glDirectDrawSurface7 *This, REFGUID guidTag, LPVOID  lpBuffer, LPDWORD lpcbBufferSize);
	HRESULT(WINAPI *FreePrivateData)(glDirectDrawSurface7 *This, REFGUID guidTag);
	HRESULT(WINAPI *GetUniquenessValue)(glDirectDrawSurface7 *This, LPDWORD lpValue);
	HRESULT(WINAPI *ChangeUniquenessValue)(glDirectDrawSurface7 *This);
	HRESULT(WINAPI *SetPriority)(glDirectDrawSurface7 *This, DWORD dwPriority);
	HRESULT(WINAPI *GetPriority)(glDirectDrawSurface7 *This, LPDWORD lpdwPriority);
	HRESULT(WINAPI *SetLOD)(glDirectDrawSurface7 *This, DWORD dwMaxLOD);
	HRESULT(WINAPI *GetLOD)(glDirectDrawSurface7 *This, LPDWORD lpdwMaxLOD);
} glDirectDrawSurface7Vtbl;

HRESULT glDirectDrawSurface7_Create(LPDIRECTDRAW7 lpDD7, LPDDSURFACEDESC2 lpDDSurfaceDesc2, HRESULT *error, glDirectDrawPalette *palettein,
	glTexture *parenttex, DWORD miplevel, int version, glDirectDrawSurface7 *front, glDirectDrawSurface7 **glDDS7);
void glDirectDrawSurface7_Delete(glDirectDrawSurface7 *This);
// ddraw 1+ api
HRESULT WINAPI glDirectDrawSurface7_QueryInterface(glDirectDrawSurface7 *This, REFIID riid, void** ppvObj);
ULONG WINAPI glDirectDrawSurface7_AddRef(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_Release(glDirectDrawSurface7 *This);
HRESULT WINAPI glDirectDrawSurface7_AddAttachedSurface(glDirectDrawSurface7 *This, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface);
HRESULT WINAPI glDirectDrawSurface7_AddOverlayDirtyRect(glDirectDrawSurface7 *This, LPRECT lpRect);
HRESULT WINAPI glDirectDrawSurface7_Blt(glDirectDrawSurface7 *This, LPRECT lpDestRect, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
HRESULT WINAPI glDirectDrawSurface7_BltBatch(glDirectDrawSurface7 *This, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface7_BltFast(glDirectDrawSurface7 *This, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
HRESULT WINAPI glDirectDrawSurface7_DeleteAttachedSurface(glDirectDrawSurface7 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface);
HRESULT WINAPI glDirectDrawSurface7_EnumAttachedSurfaces(glDirectDrawSurface7 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpEnumSurfacesCallback);
HRESULT WINAPI glDirectDrawSurface7_EnumOverlayZOrders(glDirectDrawSurface7 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpfnCallback);
HRESULT WINAPI glDirectDrawSurface7_Flip(glDirectDrawSurface7 *This, LPDIRECTDRAWSURFACE7 lpDDSurfaceTargetOverride, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface7_GetAttachedSurface(glDirectDrawSurface7 *This, LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE7 FAR *lplpDDAttachedSurface);
HRESULT WINAPI glDirectDrawSurface7_GetBltStatus(glDirectDrawSurface7 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface7_GetCaps(glDirectDrawSurface7 *This, LPDDSCAPS2 lpDDSCaps);
HRESULT WINAPI glDirectDrawSurface7_GetClipper(glDirectDrawSurface7 *This, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
HRESULT WINAPI glDirectDrawSurface7_GetColorKey(glDirectDrawSurface7 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
HRESULT WINAPI glDirectDrawSurface7_GetDC(glDirectDrawSurface7 *This, HDC FAR *lphDC);
HRESULT WINAPI glDirectDrawSurface7_GetFlipStatus(glDirectDrawSurface7 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface7_GetOverlayPosition(glDirectDrawSurface7 *This, LPLONG lplX, LPLONG lplY);
HRESULT WINAPI glDirectDrawSurface7_GetPalette(glDirectDrawSurface7 *This, LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
HRESULT WINAPI glDirectDrawSurface7_GetPixelFormat(glDirectDrawSurface7 *This, LPDDPIXELFORMAT lpDDPixelFormat);
HRESULT WINAPI glDirectDrawSurface7_GetSurfaceDesc(glDirectDrawSurface7 *This, LPDDSURFACEDESC2 lpDDSurfaceDesc);
HRESULT WINAPI glDirectDrawSurface7_Initialize(glDirectDrawSurface7 *This, LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc);
HRESULT WINAPI glDirectDrawSurface7_IsLost(glDirectDrawSurface7 *This);
HRESULT WINAPI glDirectDrawSurface7_Lock(glDirectDrawSurface7 *This, LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
HRESULT WINAPI glDirectDrawSurface7_ReleaseDC(glDirectDrawSurface7 *This, HDC hDC);
HRESULT WINAPI glDirectDrawSurface7_Restore(glDirectDrawSurface7 *This);
HRESULT WINAPI glDirectDrawSurface7_SetClipper(glDirectDrawSurface7 *This, LPDIRECTDRAWCLIPPER lpDDClipper);
HRESULT WINAPI glDirectDrawSurface7_SetColorKey(glDirectDrawSurface7 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
HRESULT WINAPI glDirectDrawSurface7_SetOverlayPosition(glDirectDrawSurface7 *This, LONG lX, LONG lY);
HRESULT WINAPI glDirectDrawSurface7_SetPalette(glDirectDrawSurface7 *This, LPDIRECTDRAWPALETTE lpDDPalette);
HRESULT WINAPI glDirectDrawSurface7_Unlock(glDirectDrawSurface7 *This, LPRECT lpRect);
HRESULT WINAPI glDirectDrawSurface7_UpdateOverlay(glDirectDrawSurface7 *This, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE7 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
HRESULT WINAPI glDirectDrawSurface7_UpdateOverlayDisplay(glDirectDrawSurface7 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface7_UpdateOverlayZOrder(glDirectDrawSurface7 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSReference);
// ddraw 2+ api
HRESULT WINAPI glDirectDrawSurface7_GetDDInterface(glDirectDrawSurface7 *This, LPVOID FAR *lplpDD);
HRESULT WINAPI glDirectDrawSurface7_PageLock(glDirectDrawSurface7 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface7_PageUnlock(glDirectDrawSurface7 *This, DWORD dwFlags);
// ddraw 3+ api
HRESULT WINAPI glDirectDrawSurface7_SetSurfaceDesc(glDirectDrawSurface7 *This, LPDDSURFACEDESC2 lpddsd2, DWORD dwFlags);
// ddraw 4+ api
HRESULT WINAPI glDirectDrawSurface7_SetPrivateData(glDirectDrawSurface7 *This, REFGUID guidTag, LPVOID  lpData, DWORD   cbSize, DWORD   dwFlags);
HRESULT WINAPI glDirectDrawSurface7_GetPrivateData(glDirectDrawSurface7 *This, REFGUID guidTag, LPVOID  lpBuffer, LPDWORD lpcbBufferSize);
HRESULT WINAPI glDirectDrawSurface7_FreePrivateData(glDirectDrawSurface7 *This, REFGUID guidTag);
HRESULT WINAPI glDirectDrawSurface7_GetUniquenessValue(glDirectDrawSurface7 *This, LPDWORD lpValue);
HRESULT WINAPI glDirectDrawSurface7_ChangeUniquenessValue(glDirectDrawSurface7 *This);
// ddraw 7 api
HRESULT WINAPI glDirectDrawSurface7_SetPriority(glDirectDrawSurface7 *This, DWORD dwPriority);
HRESULT WINAPI glDirectDrawSurface7_GetPriority(glDirectDrawSurface7 *This, LPDWORD lpdwPriority);
HRESULT WINAPI glDirectDrawSurface7_SetLOD(glDirectDrawSurface7 *This, DWORD dwMaxLOD);
HRESULT WINAPI glDirectDrawSurface7_GetLOD(glDirectDrawSurface7 *This, LPDWORD lpdwMaxLOD);
// internal functions
ULONG WINAPI glDirectDrawSurface7_AddRef4(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_Release4(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_AddRef3(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_Release3(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_AddRef2(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_Release2(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_AddRef1(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_Release1(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_AddRefGamma(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_ReleaseGamma(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_AddRefColor(glDirectDrawSurface7 *This);
ULONG WINAPI glDirectDrawSurface7_ReleaseColor(glDirectDrawSurface7 *This);
HRESULT WINAPI glDirectDrawSurface7_SetPaletteNoDraw(glDirectDrawSurface7 *This, LPDIRECTDRAWPALETTE lpDDPalette);
void glDirectDrawSurface7_Restore2(glDirectDrawSurface7 *This);
HRESULT glDirectDrawSurface7_Flip2(glDirectDrawSurface7 *This, LPDIRECTDRAWSURFACE7 lpDDSurfaceTargetOverride, DWORD dwFlags, glTexture **previous);
HRESULT glDirectDrawSurface7_AddAttachedSurface2(glDirectDrawSurface7 *This, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface, IUnknown *iface);
void glDirectDrawSurface7_SetTexture(glDirectDrawSurface7 *This, glTexture *newtexture);
void glDirectDrawSurface7_RenderScreen(glDirectDrawSurface7 *This, glTexture *texture, int vsync, glTexture *previous, BOOL settime, OVERLAY *overlays, int overlaycount);
// Special ddraw2->ddraw7 api
HRESULT WINAPI glDirectDrawSurface7_Unlock2(glDirectDrawSurface7 *This, LPVOID lpSurfaceData);
HRESULT glDirectDrawSurface7_GetHandle(glDirectDrawSurface7 *This, glDirect3DDevice7 *glD3DDev7, LPD3DTEXTUREHANDLE lpHandle);
HRESULT glDirectDrawSurface7_Load(glDirectDrawSurface7 *This, glDirectDrawSurface7 *src);
HRESULT glDirectDrawSurface7_GetGammaRamp(glDirectDrawSurface7 *This, DWORD dwFlags, LPDDGAMMARAMP lpRampData);
HRESULT glDirectDrawSurface7_SetGammaRamp(glDirectDrawSurface7 *This, DWORD dwFlags, LPDDGAMMARAMP lpRampData);
HRESULT glDirectDrawSurface7_AddOverlay(glDirectDrawSurface7 *This, OVERLAY *overlay);
HRESULT glDirectDrawSurface7_DeleteOverlay(glDirectDrawSurface7 *This, glDirectDrawSurface7 *surface);
HRESULT glDirectDrawSurface7_UpdateOverlayTexture(glDirectDrawSurface7 *This, glDirectDrawSurface7 *surface, glTexture *texture);

// Legacy DDRAW Interfaces
struct glDirectDrawSurface1Vtbl;
typedef struct glDirectDrawSurface1
{
	glDirectDrawSurface1Vtbl *lpVtbl;
	glDirectDrawSurface7 *glDDS7;
} glDirectDrawSurface1;
typedef struct glDirectDrawSurface1Vtbl
{
	HRESULT(WINAPI *QueryInterface)(glDirectDrawSurface1 *This, REFIID riid, void** ppvObj);
	ULONG(WINAPI *Release)(glDirectDrawSurface1 *This);
	ULONG(WINAPI *AddRef)(glDirectDrawSurface1 *This);
	HRESULT(WINAPI *AddAttachedSurface)(glDirectDrawSurface1 *This, LPDIRECTDRAWSURFACE lpDDSAttachedSurface);
	HRESULT(WINAPI *AddOverlayDirtyRect)(glDirectDrawSurface1 *This, LPRECT lpRect);
	HRESULT(WINAPI *Blt)(glDirectDrawSurface1 *This, LPRECT lpDestRect, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
	HRESULT(WINAPI *BltBatch)(glDirectDrawSurface1 *This, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
	HRESULT(WINAPI *BltFast)(glDirectDrawSurface1 *This, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
	HRESULT(WINAPI *DeleteAttachedSurface)(glDirectDrawSurface1 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSAttachedSurface);
	HRESULT(WINAPI *EnumAttachedSurfaces)(glDirectDrawSurface1 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
	HRESULT(WINAPI *EnumOverlayZOrders)(glDirectDrawSurface1 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback);
	HRESULT(WINAPI *Flip)(glDirectDrawSurface1 *This, LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride, DWORD dwFlags);
	HRESULT(WINAPI *GetAttachedSurface)(glDirectDrawSurface1 *This, LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface);
	HRESULT(WINAPI *GetBltStatus)(glDirectDrawSurface1 *This, DWORD dwFlags);
	HRESULT(WINAPI *GetCaps)(glDirectDrawSurface1 *This, LPDDSCAPS lpDDSCaps);
	HRESULT(WINAPI *GetClipper)(glDirectDrawSurface1 *This, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
	HRESULT(WINAPI *GetColorKey)(glDirectDrawSurface1 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT(WINAPI *GetDC)(glDirectDrawSurface1 *This, HDC FAR *lphDC);
	HRESULT(WINAPI *GetFlipStatus)(glDirectDrawSurface1 *This, DWORD dwFlags);
	HRESULT(WINAPI *GetOverlayPosition)(glDirectDrawSurface1 *This, LPLONG lplX, LPLONG lplY);
	HRESULT(WINAPI *GetPalette)(glDirectDrawSurface1 *This, LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
	HRESULT(WINAPI *GetPixelFormat)(glDirectDrawSurface1 *This, LPDDPIXELFORMAT lpDDPixelFormat);
	HRESULT(WINAPI *GetSurfaceDesc)(glDirectDrawSurface1 *This, LPDDSURFACEDESC lpDDSurfaceDesc);
	HRESULT(WINAPI *Initialize)(glDirectDrawSurface1 *This, LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc);
	HRESULT(WINAPI *IsLost)(glDirectDrawSurface1 *This);
	HRESULT(WINAPI *Lock)(glDirectDrawSurface1 *This, LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
	HRESULT(WINAPI *ReleaseDC)(glDirectDrawSurface1 *This, HDC hDC);
	HRESULT(WINAPI *Restore)(glDirectDrawSurface1 *This);
	HRESULT(WINAPI *SetClipper)(glDirectDrawSurface1 *This, LPDIRECTDRAWCLIPPER lpDDClipper);
	HRESULT(WINAPI *SetColorKey)(glDirectDrawSurface1 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT(WINAPI *SetOverlayPosition)(glDirectDrawSurface1 *This, LONG lX, LONG lY);
	HRESULT(WINAPI *SetPalette)(glDirectDrawSurface1 *This, LPDIRECTDRAWPALETTE lpDDPalette);
	HRESULT(WINAPI *Unlock)(glDirectDrawSurface1 *This, LPVOID lpSurfaceData);
	HRESULT(WINAPI *UpdateOverlay)(glDirectDrawSurface1 *This, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
	HRESULT(WINAPI *UpdateOverlayDisplay)(glDirectDrawSurface1 *This, DWORD dwFlags);
	HRESULT(WINAPI *UpdateOverlayZOrder)(glDirectDrawSurface1 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSReference);
} glDirectDrawSurface1Vtbl;


HRESULT glDirectDrawSurface1_Create(glDirectDrawSurface7 *gl_DDS7, glDirectDrawSurface1 **glDDS1);
// ddraw 1+ api
HRESULT WINAPI glDirectDrawSurface1_QueryInterface(glDirectDrawSurface1 *This, REFIID riid, void** ppvObj);
ULONG WINAPI glDirectDrawSurface1_AddRef(glDirectDrawSurface1 *This);
ULONG WINAPI glDirectDrawSurface1_Release(glDirectDrawSurface1 *This);
HRESULT WINAPI glDirectDrawSurface1_AddAttachedSurface(glDirectDrawSurface1 *This, LPDIRECTDRAWSURFACE lpDDSAttachedSurface);
HRESULT WINAPI glDirectDrawSurface1_AddOverlayDirtyRect(glDirectDrawSurface1 *This, LPRECT lpRect);
HRESULT WINAPI glDirectDrawSurface1_Blt(glDirectDrawSurface1 *This, LPRECT lpDestRect, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
HRESULT WINAPI glDirectDrawSurface1_BltBatch(glDirectDrawSurface1 *This, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface1_BltFast(glDirectDrawSurface1 *This, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
HRESULT WINAPI glDirectDrawSurface1_DeleteAttachedSurface(glDirectDrawSurface1 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSAttachedSurface);
HRESULT WINAPI glDirectDrawSurface1_EnumAttachedSurfaces(glDirectDrawSurface1 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
HRESULT WINAPI glDirectDrawSurface1_EnumOverlayZOrders(glDirectDrawSurface1 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback);
HRESULT WINAPI glDirectDrawSurface1_Flip(glDirectDrawSurface1 *This, LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface1_GetAttachedSurface(glDirectDrawSurface1 *This, LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE FAR *lplpDDAttachedSurface);
HRESULT WINAPI glDirectDrawSurface1_GetBltStatus(glDirectDrawSurface1 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface1_GetCaps(glDirectDrawSurface1 *This, LPDDSCAPS lpDDSCaps);
HRESULT WINAPI glDirectDrawSurface1_GetClipper(glDirectDrawSurface1 *This, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
HRESULT WINAPI glDirectDrawSurface1_GetColorKey(glDirectDrawSurface1 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
HRESULT WINAPI glDirectDrawSurface1_GetDC(glDirectDrawSurface1 *This, HDC FAR *lphDC);
HRESULT WINAPI glDirectDrawSurface1_GetFlipStatus(glDirectDrawSurface1 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface1_GetOverlayPosition(glDirectDrawSurface1 *This, LPLONG lplX, LPLONG lplY);
HRESULT WINAPI glDirectDrawSurface1_GetPalette(glDirectDrawSurface1 *This, LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
HRESULT WINAPI glDirectDrawSurface1_GetPixelFormat(glDirectDrawSurface1 *This, LPDDPIXELFORMAT lpDDPixelFormat);
HRESULT WINAPI glDirectDrawSurface1_GetSurfaceDesc(glDirectDrawSurface1 *This, LPDDSURFACEDESC lpDDSurfaceDesc);
HRESULT WINAPI glDirectDrawSurface1_Initialize(glDirectDrawSurface1 *This, LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc);
HRESULT WINAPI glDirectDrawSurface1_IsLost(glDirectDrawSurface1 *This);
HRESULT WINAPI glDirectDrawSurface1_Lock(glDirectDrawSurface1 *This, LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
HRESULT WINAPI glDirectDrawSurface1_ReleaseDC(glDirectDrawSurface1 *This, HDC hDC);
HRESULT WINAPI glDirectDrawSurface1_Restore(glDirectDrawSurface1 *This);
HRESULT WINAPI glDirectDrawSurface1_SetClipper(glDirectDrawSurface1 *This, LPDIRECTDRAWCLIPPER lpDDClipper);
HRESULT WINAPI glDirectDrawSurface1_SetColorKey(glDirectDrawSurface1 *This, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
HRESULT WINAPI glDirectDrawSurface1_SetOverlayPosition(glDirectDrawSurface1 *This, LONG lX, LONG lY);
HRESULT WINAPI glDirectDrawSurface1_SetPalette(glDirectDrawSurface1 *This, LPDIRECTDRAWPALETTE lpDDPalette);
HRESULT WINAPI glDirectDrawSurface1_Unlock(glDirectDrawSurface1 *This, LPVOID lpSurfaceData);
HRESULT WINAPI glDirectDrawSurface1_UpdateOverlay(glDirectDrawSurface1 *This, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
HRESULT WINAPI glDirectDrawSurface1_UpdateOverlayDisplay(glDirectDrawSurface1 *This, DWORD dwFlags);
HRESULT WINAPI glDirectDrawSurface1_UpdateOverlayZOrder(glDirectDrawSurface1 *This, DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSReference);

class glDirectDrawSurface2 : public IDirectDrawSurface2
{
public:
	glDirectDrawSurface2(glDirectDrawSurface7 *gl_DDS7);
	// ddraw 1+ api
	HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObj);
	ULONG WINAPI AddRef();
	ULONG WINAPI Release();
	HRESULT WINAPI AddAttachedSurface(LPDIRECTDRAWSURFACE2 lpDDSAttachedSurface);
	HRESULT WINAPI AddOverlayDirtyRect(LPRECT lpRect);
	HRESULT WINAPI Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE2 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
	HRESULT WINAPI BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
	HRESULT WINAPI BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE2 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
	HRESULT WINAPI DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE2 lpDDSAttachedSurface);
	HRESULT WINAPI EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
	HRESULT WINAPI EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback);
	HRESULT WINAPI Flip(LPDIRECTDRAWSURFACE2 lpDDSurfaceTargetOverride, DWORD dwFlags);
	HRESULT WINAPI GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE2 FAR *lplpDDAttachedSurface);
	HRESULT WINAPI GetBltStatus(DWORD dwFlags);
	HRESULT WINAPI GetCaps(LPDDSCAPS lpDDSCaps);
	HRESULT WINAPI GetClipper(LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
	HRESULT WINAPI GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT WINAPI GetDC(HDC FAR *lphDC);
	HRESULT WINAPI GetFlipStatus(DWORD dwFlags);
	HRESULT WINAPI GetOverlayPosition(LPLONG lplX, LPLONG lplY);
	HRESULT WINAPI GetPalette(LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
	HRESULT WINAPI GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat);
	HRESULT WINAPI GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc);
	HRESULT WINAPI Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc);
	HRESULT WINAPI IsLost();
	HRESULT WINAPI Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
	HRESULT WINAPI ReleaseDC(HDC hDC);
	HRESULT WINAPI Restore();
	HRESULT WINAPI SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper);
	HRESULT WINAPI SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT WINAPI SetOverlayPosition(LONG lX, LONG lY);
	HRESULT WINAPI SetPalette(LPDIRECTDRAWPALETTE lpDDPalette);
	HRESULT WINAPI Unlock(LPVOID lpSurfaceData);
	HRESULT WINAPI UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE2 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
	HRESULT WINAPI UpdateOverlayDisplay(DWORD dwFlags);
	HRESULT WINAPI UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE2 lpDDSReference);
	// ddraw 2+ api
	HRESULT WINAPI GetDDInterface(LPVOID FAR *lplpDD);
	HRESULT WINAPI PageLock(DWORD dwFlags);
	HRESULT WINAPI PageUnlock(DWORD dwFlags);
	glDirectDrawSurface7 *GetDDS7() {return glDDS7;};
private:
	glDirectDrawSurface7 *glDDS7;
};
class glDirectDrawSurface3 : public IDirectDrawSurface3
{
public:
	glDirectDrawSurface3(glDirectDrawSurface7 *gl_DDS7);
	// ddraw 1+ api
	HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObj);
	ULONG WINAPI AddRef();
	ULONG WINAPI Release();
	HRESULT WINAPI AddAttachedSurface(LPDIRECTDRAWSURFACE3 lpDDSAttachedSurface);
	HRESULT WINAPI AddOverlayDirtyRect(LPRECT lpRect);
	HRESULT WINAPI Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE3 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
	HRESULT WINAPI BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
	HRESULT WINAPI BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE3 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
	HRESULT WINAPI DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE3 lpDDSAttachedSurface);
	HRESULT WINAPI EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
	HRESULT WINAPI EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback);
	HRESULT WINAPI Flip(LPDIRECTDRAWSURFACE3 lpDDSurfaceTargetOverride, DWORD dwFlags);
	HRESULT WINAPI GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE3 FAR *lplpDDAttachedSurface);
	HRESULT WINAPI GetBltStatus(DWORD dwFlags);
	HRESULT WINAPI GetCaps(LPDDSCAPS lpDDSCaps);
	HRESULT WINAPI GetClipper(LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
	HRESULT WINAPI GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT WINAPI GetDC(HDC FAR *lphDC);
	HRESULT WINAPI GetFlipStatus(DWORD dwFlags);
	HRESULT WINAPI GetOverlayPosition(LPLONG lplX, LPLONG lplY);
	HRESULT WINAPI GetPalette(LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
	HRESULT WINAPI GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat);
	HRESULT WINAPI GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc);
	HRESULT WINAPI Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc);
	HRESULT WINAPI IsLost();
	HRESULT WINAPI Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
	HRESULT WINAPI ReleaseDC(HDC hDC);
	HRESULT WINAPI Restore();
	HRESULT WINAPI SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper);
	HRESULT WINAPI SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT WINAPI SetOverlayPosition(LONG lX, LONG lY);
	HRESULT WINAPI SetPalette(LPDIRECTDRAWPALETTE lpDDPalette);
	HRESULT WINAPI Unlock(LPVOID lpSurfaceData);
	HRESULT WINAPI UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE3 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
	HRESULT WINAPI UpdateOverlayDisplay(DWORD dwFlags);
	HRESULT WINAPI UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE3 lpDDSReference);
	// ddraw 2+ api
	HRESULT WINAPI GetDDInterface(LPVOID FAR *lplpDD);
	HRESULT WINAPI PageLock(DWORD dwFlags);
	HRESULT WINAPI PageUnlock(DWORD dwFlags);
	// ddraw 3+ api
	HRESULT WINAPI SetSurfaceDesc(LPDDSURFACEDESC lpddsd2, DWORD dwFlags);
	glDirectDrawSurface7 *GetDDS7() {return glDDS7;};
private:
	glDirectDrawSurface7 *glDDS7;
};
class glDirectDrawSurface4 : public IDirectDrawSurface4
{
public:
	glDirectDrawSurface4(glDirectDrawSurface7 *gl_DDS7);
	// ddraw 1+ api
	HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObj);
	ULONG WINAPI AddRef();
	ULONG WINAPI Release();
	HRESULT WINAPI AddAttachedSurface(LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface);
	HRESULT WINAPI AddOverlayDirtyRect(LPRECT lpRect);
	HRESULT WINAPI Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
	HRESULT WINAPI BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
	HRESULT WINAPI BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
	HRESULT WINAPI DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface);
	HRESULT WINAPI EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback);
	HRESULT WINAPI EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback);
	HRESULT WINAPI Flip(LPDIRECTDRAWSURFACE4 lpDDSurfaceTargetOverride, DWORD dwFlags);
	HRESULT WINAPI GetAttachedSurface(LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE4 FAR *lplpDDAttachedSurface);
	HRESULT WINAPI GetBltStatus(DWORD dwFlags);
	HRESULT WINAPI GetCaps(LPDDSCAPS2 lpDDSCaps);
	HRESULT WINAPI GetClipper(LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
	HRESULT WINAPI GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT WINAPI GetDC(HDC FAR *lphDC);
	HRESULT WINAPI GetFlipStatus(DWORD dwFlags);
	HRESULT WINAPI GetOverlayPosition(LPLONG lplX, LPLONG lplY);
	HRESULT WINAPI GetPalette(LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
	HRESULT WINAPI GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat);
	HRESULT WINAPI GetSurfaceDesc(LPDDSURFACEDESC2 lpDDSurfaceDesc);
	HRESULT WINAPI Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc);
	HRESULT WINAPI IsLost();
	HRESULT WINAPI Lock(LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
	HRESULT WINAPI ReleaseDC(HDC hDC);
	HRESULT WINAPI Restore();
	HRESULT WINAPI SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper);
	HRESULT WINAPI SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
	HRESULT WINAPI SetOverlayPosition(LONG lX, LONG lY);
	HRESULT WINAPI SetPalette(LPDIRECTDRAWPALETTE lpDDPalette);
	HRESULT WINAPI Unlock(LPRECT lpRect);
	HRESULT WINAPI UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE4 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
	HRESULT WINAPI UpdateOverlayDisplay(DWORD dwFlags);
	HRESULT WINAPI UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSReference);
	// ddraw 2+ api
	HRESULT WINAPI GetDDInterface(LPVOID FAR *lplpDD);
	HRESULT WINAPI PageLock(DWORD dwFlags);
	HRESULT WINAPI PageUnlock(DWORD dwFlags);
	// ddraw 3+ api
	HRESULT WINAPI SetSurfaceDesc(LPDDSURFACEDESC2 lpddsd2, DWORD dwFlags);
	// ddraw 4+ api
	HRESULT WINAPI SetPrivateData(REFGUID guidTag, LPVOID  lpData, DWORD   cbSize, DWORD   dwFlags);
	HRESULT WINAPI GetPrivateData(REFGUID guidTag, LPVOID  lpBuffer, LPDWORD lpcbBufferSize);
	HRESULT WINAPI FreePrivateData(REFGUID guidTag);
	HRESULT WINAPI GetUniquenessValue(LPDWORD lpValue);
	HRESULT WINAPI ChangeUniquenessValue();
	glDirectDrawSurface7 *GetDDS7() {return glDDS7;};
private:
	glDirectDrawSurface7 *glDDS7;
};
#endif //_GLDIRECTDRAWSURFACE_H
