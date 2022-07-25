#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../rwbase.h"
#include "../rwerror.h"
#include "../rwplg.h"
#include "../rwpipeline.h"
#include "../rwobjects.h"
#include "../rwengine.h"

#include "rwgl1.h"
#include "rwgl1shader.h"

#include "rwgl1impl.h"

namespace rw {
namespace gl1 {

// TODO: make some of these things platform-independent

static void*
driverOpen(void *o, int32, int32)
{
#ifdef RW_OPENGL1
	engine->driver[PLATFORM_GL1]->defaultPipeline = makeDefaultPipeline();
#endif
	engine->driver[PLATFORM_GL1]->rasterNativeOffset = nativeRasterOffset;
	engine->driver[PLATFORM_GL1]->rasterCreate       = rasterCreate;
	engine->driver[PLATFORM_GL1]->rasterLock         = rasterLock;
	engine->driver[PLATFORM_GL1]->rasterUnlock       = rasterUnlock;
	engine->driver[PLATFORM_GL1]->rasterNumLevels    = rasterNumLevels;
	engine->driver[PLATFORM_GL1]->imageFindRasterFormat = imageFindRasterFormat;
	engine->driver[PLATFORM_GL1]->rasterFromImage    = rasterFromImage;
	engine->driver[PLATFORM_GL1]->rasterToImage      = rasterToImage;

	return o;
}

static void*
driverClose(void *o, int32, int32)
{
	return o;
}

void
registerPlatformPlugins(void)
{
	Driver::registerPlugin(PLATFORM_GL1, 0, PLATFORM_GL1,
	                       driverOpen, driverClose);
	registerNativeRaster();
}

}
}
