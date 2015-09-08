

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "gtest/gtest.h"
#include "llt_mockcpp.h"

using namespace testing;
#ifdef __cplusplus
extern "C"
{
#endif

	#ifndef OK
	#define OK 0
	#endif

	#ifndef ERROR
	#define ERROR (-1)
	#endif

    extern int  ashell_init(void);
    extern int  ashell_uninit(void);
    extern int  usb_tty_exist(char *tty_name);
    extern void ashell_console_write(struct console *cons, const char *buf, unsigned count);
    extern int  usb_shell_init(void);

    extern void *dma_alloc_coherent(struct device *dev, size_t size, unsigned long long *dma_handle, int  flag);

    extern long sys_write(unsigned int fd, const char  *buf, long unsigned int count);
    extern signed int udi_read(signed int handle, void* pMemObj, unsigned int u32Size);
    extern struct cshell_ctx_t g_cshell_ctx;

    int g_buf;

    extern int test_ashell_console_write_fail1(void);
    extern int test_ashell_console_write_fail2(void);
    extern int test_ashell_console_write_fail3(void);
    extern int test_ashell_console_write_fail4(void);
    extern int test_ashell_console_write_ok(void);


    /* ���⺯�� */

    /* ����ȫ�ֱ��� */

#ifdef __cplusplus
}
#endif

#if 0

/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_ashell_init, UT001_ashell_init_ok)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/
    int ret = 0;

    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/


    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/
    MOCKER(dma_alloc_coherent).stubs().will(returnValue(1));
    ret = ashell_init();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(-1,ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
    	GlobalMockObject::reset();
}
#endif


/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_ashell_console_write, UT001_param_is_error)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/

    int ret = 0;
    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/

    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = test_ashell_console_write_fail1();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(ERROR, ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
}



/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_ashell_console_write, UT002_tty_is_null)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/

    int ret = 0;
    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/

    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = test_ashell_console_write_fail2();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(ERROR, ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
}



/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_ashell_console_write, UT003_device_fail)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/
    int ret = 0;
    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/

    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = test_ashell_console_write_fail3();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(ERROR, ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
}


/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_ashell_console_write, UT004_write_fail)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/
    int ret = 0;
    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/

    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = test_ashell_console_write_fail4();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(ERROR, ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
}


/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_ashell_console_write, UT005_write_success)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/
    int ret = 0;
    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/

    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = test_ashell_console_write_ok();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(OK, ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
}


/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_usb_shell_init, UT001_ashell_init_tty_not_exist_fail)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/

    int ret = 0;
    MOCKER(usb_tty_exist).stubs().will(returnValue(ERROR));

    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/


    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = usb_shell_init();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(OK,ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
	GlobalMockObject::reset();
}



/*****************************************************************************
  (1)׮��������
*****************************************************************************/


/*****************************************************************************
  (2)UT����ʵ��
*****************************************************************************/
TEST(test_usb_shell_init, UT002_init_success)
{

    /*************************************************************************
      (1)��ʼ�����Ի���
    *************************************************************************/

    int ret = 0;

    MOCKER(usb_tty_exist).stubs().will(returnValue(0));

    /*************************************************************************
      (2)���ñ��⺯���β�
    *************************************************************************/


    /*************************************************************************
      (3)ִ�б��⺯��
    *************************************************************************/

    ret = usb_shell_init();

    /*************************************************************************
      (4)�����Խ��
    *************************************************************************/
    EXPECT_EQ(OK,ret);

    /*************************************************************************
      (5)�������Ի���
    *************************************************************************/
	GlobalMockObject::reset();

}
