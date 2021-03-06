/*
 * =====================================================================================
 *
 *       Filename:  led.c
 *
 *    Description:  led HAL层的实现
 *
 *        Version:  1.0
 *        Created:  03/09/2018 01:15:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hang Cao (Melvin), hang.yasuo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <errno.h>
#include <led.h> //Android.mk中指定后，相对路径include

#define LOG_TAG "TestLedStub"
int led_device_open(const struct hw_module_t*, const char*, struct hw_device_t**);
int led_device_close(struct hw_device_t*);

//HAL_MODULE_INFO_SYM是一个宏定义(#define HAML_MODULE_INFO) HMI)，load是通过这个宏找到地址
const struct led_module_t HAL_MODULE_INFO_SYM = {
    common : {
        tag : HARDWARE_MODULE_TAG,
        version_major : 1,
        version_minor : 0,
        id : LED_HARDWARE_MODULE_ID, //led.goldfish中的led?
        author : "melvin",
        methods : &led_module_methods,
    },
    //这里添加支持的API
};
struct hw_module_methods_t led_module_methods = {
    open : led_device_open
};

int led_device_open(const struct hw_module_t* module, const char* name, struct hw_device_t** device)
{
    struct led_control_device_t* dev;
    dev = (struct led_control_device_t*)malloc(sizeof(*dev));
    memset(dev, 0, sizeof(*dev));
    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = 0;
    dev->common.module = module;
    dev->common.close = led_device_close;

    dev->set_on = led_on;
    dev->set_off = led_off;
    *device = &dev->common;

    //打开设备文件
    dev->fd = open("/dev/cdata-test", O_RDWR);
success:
    return 0;
}

int led_device_close(struct hw_device_t* device)
{
    return 0;
}

int led_on(struct led_control_device_t* dev, int32_t led)
{
    int fd;
    ALOGI("LED Stub:set %d on", led);
    fd = dev->fd;
    ioctl(fd, 0, 0);
    sleep(30);
    ALOGI("LED On:wake up...");
    return 0;
}
int led_off(struct led_control_device_t* dev, int32 led)
{
    int fd;
    ALOGI("LED Stub: set%d off", led);
    fd = dev->fd;
    ioctl(fd, 0, 0);
    sleep(30);

    ALOGI("LED Off:wake up ..");
    return 0;
}
