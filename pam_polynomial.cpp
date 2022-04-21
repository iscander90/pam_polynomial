#include "pam_polynomial.h"

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char *argv[])
{
//переменные
    /*- получение имя пользователя заявителя-*/
    const char * c_username;
    /*--variables for pam --*/
    const void *m_ptr;
    struct pam_message m_msg;
    const struct pam_message *m_msgp;
    struct pam_response *m_resp;
    const struct pam_conv *m_conv;
    int retval;
/*--переменные для формирование многочлена у=x*x+a*x+b --*/
    int y;
    int x = rand()%5;
    int a = rand()%10;
    int b = rand()%100;
    /*---количество попыток неправильного ответа значение многочлена ----*/
    int retry=3;
    /*--- переменный для хранение ответ пользователя ----*/
    char *user_answer;
    if ((retval = pam_get_user(pamh, (const char**)&c_username, NULL))!=PAM_SUCCESS){return (retval);}
    retval=pam_get_item(pamh,PAM_CONV,(const void **)&m_ptr);
    if (retval!=PAM_SUCCESS) {return(PAM_SYSTEM_ERR); }
    m_conv=(const struct pam_conv*)m_ptr;
    m_msg.msg_style=PAM_PROMPT_ECHO_OFF;
    //сообщение пользователю с аргументами многочлена
    QString message="x="+QString().setNum(x)+";"+"a="+QString().setNum(a)+";"+"b="+QString().setNum(b);
    m_msg.msg=message.toLocal8Bit().constData();
    m_msgp=&m_msg;

//запрос ответ пользователя
for (int i=0;i<retry;i++)
{
    m_resp=NULL;
    retval=(*m_conv->conv)(1,&m_msgp,&m_resp,m_conv->appdata_ptr);
    if (m_resp!=NULL)
    {
        if (retval==PAM_SUCCESS) { user_answer=m_resp->resp;}
        else
        {
            free(m_resp->resp);
            free(m_resp);
        }
    }
    if (retval==PAM_SUCCESS) {break;}
}
if (retval == PAM_CONV_ERR) return (retval);
if (retval != PAM_SUCCESS) {return (PAM_AUTH_ERR);}
y = x*x+a*x+b;
//проверка
if (y!=QString(user_answer).toInt())
{
      return (retval=PAM_AUTH_ERR);
}
else
{
    return retval;
    free(user_answer);
}
return (retval);
}

int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
        return PAM_SUCCESS;
}
   int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
       return PAM_SUCCESS;
}
