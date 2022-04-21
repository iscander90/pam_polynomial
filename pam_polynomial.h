#ifndef PAM_POLYNOMIAL_H
#define PAM_POLYNOMIAL_H

#include "pam_polynomial_global.h"
// Подключаем заголовочных файлов библиотек Linux-PAM и Linux-PAM-MISC
#include <security/pam_modules.h>
#include <security/pam_appl.h>
#include <security/pam_ext.h>
// Стандартный заголовочный файл для генерации случайного числа
#include <stdlib.h>
// Заловочный файл для работы строкового типа QT фреймворка
#include <QString>
// интерфейс Linux-PAM для организации аутентификацию
int PAM_POLYNOMIAL_EXPORT pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char *argv[]);
// интерфейс Linux-PAM для организациия авторизацию, то есть устанавление uid
int PAM_POLYNOMIAL_EXPORT pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv);
// интерфейс Linux-PAM для управление учетными данными
int PAM_POLYNOMIAL_EXPORT pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv);

#endif // PAM_POLYNOMIAL_H
