#include <stdio.h>
#include <stdlib.h>

#include <libvmdk.h>

int TestVmdk(const char *filename)
{
    int ret = -1;
    libvmdk_error_t *error = NULL;
    libvmdk_handle_t *handle = NULL;
    int disk_type = 0;
    size64_t size = 0;



    if( libvmdk_handle_initialize(&handle, &error) != 1 )
    {
        fprintf(stderr, "Unable to initialize handle.\n");
        libvmdk_error_free(&error);
        return EXIT_FAILURE;
    }

    if( libvmdk_handle_open(handle, filename, LIBVMDK_OPEN_READ, &error) != 1 )
    {
        fprintf(stderr, "Unable to open handle.\n" );
        goto out;
    }

    printf("Handle opened \n");

    if (libvmdk_handle_get_disk_type(handle, &disk_type, &error) != 1)
    {
        fprintf(stderr, "Unable to get disk type.\n" );
    }

    printf ("Disk type: %d\n", disk_type);

    if ( libvmdk_handle_get_media_size(handle, &size, &error) != 1)
    {
        fprintf(stderr, "Unable to get media size.\n" );
    }

    printf ("Disk type: %lu\n", size);

    if ( libvmdk_handle_close(handle, &error) != 0)
    {
        fprintf(stderr, "Unable to close handle.\n" );
        goto out;
    }

    ret = 0;
out:
    if( libvmdk_handle_free(&handle, &error) != 1 )
    {
        fprintf(stderr, "Unable to free handle.\n");
        libvmdk_error_free(&error);
        return EXIT_FAILURE;
    } 

    return ret;
}

int TestFunction()
{
    return TestVmdk("/work/win7-disk1.vmdk"); 
}

int main(int argc, char *argv[])
{
    int ret = 0;

    ret = TestFunction();

    if (ret != 0)
    {
        printf ("Test failed: %d\n", ret);
    }

    return ret;
} 
