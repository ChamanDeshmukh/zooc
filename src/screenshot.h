#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#ifdef MITSHM
#include <X11/extensions/XShm.h>
#endif

typedef struct Screenshot {
    XImage *image;
#ifdef MITSHM
    XShmSegmentInfo *shminfo;
#endif
} Screenshot;

Screenshot newScreenshot(Display *display, Window window);
void destroyScreenshot(Screenshot screenshot, Display *display);
void refreshScreenshot(Screenshot *screenshot, Display *display, Window window);
void saveToPPM(XImage *image, const char *filePath);
void cleanupScreenshot(Screenshot *screenshot);

#endif /* SCREENSHOT_H */
