#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>

int main(int argc, const char * argv[]) {
    uint32_t maxDisplays = 256;
    CGDirectDisplayID activeDisplays[maxDisplays];
    uint32_t displayCount = 0;
    
    CGError error = CGGetActiveDisplayList(maxDisplays, activeDisplays, &displayCount);

    if (error != kCGErrorSuccess) {
        fprintf(stderr, "Quartz error %d.  See http://developer.apple.com/library/mac/#documentation/CoreGraphics/Reference/CoreGraphicsConstantsRef/Reference/reference.html#//apple_ref/doc/uid/TP40008794", error);
        return error;
    }
    
    if (argc != 1) {
        fprintf(stderr, "usage: screeninfo\nprints all active display {origin, size} as an AppleScript list");
        return 2;
    }
    
    printf("{");
    for (int i = 0; i < displayCount; i++) {
        CGRect bounds = CGDisplayBounds(activeDisplays[i]);
        CGPoint origin = bounds.origin;
        CGSize size = bounds.size;
        
        printf("{{%d, %d}, {%d, %d}}", (uint32_t) origin.x, (uint32_t) origin.y, (uint32_t) size.width, (uint32_t) size.height);
        if (i != displayCount - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    
    return 0;
}

