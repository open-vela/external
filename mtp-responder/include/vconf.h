/*
 * Copyright (C) 2023 Xiaomi Corperation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __VCONF_H__
#define __VCONF_H__

#include <vconf-keys.h>

typedef struct _keynode_t {
    char* keyname; /**< Keyname for keynode */
    int type; /**< Keynode type */
    union {
        int i; /**< Integer type */
        int b; /**< Bool type */
        double d; /**< Double type */
        char* s; /**< String type */
    } value; /**< Value for keynode */
    struct _keynode_t* next; /**< Next keynode */
} keynode_t;

/**
 * @brief  Called when the key is set handle.
 * @details  This is the signature of a callback function added with vconf_notify_key_changed() handle.
 *
 * @since_tizen 2.3
 *
 * @see keynode_t
 */
typedef void (*vconf_callback_fn)(keynode_t* node, void* user_data);

/**
 * This function get the integer value of given key.
 *
 * @param[in]	in_key	key
 * @param[out]	intval output buffer
 * @return 0 on success, -1 on error
 * @pre None
 * @post None
 * @remkar None
 * @see vconf_get_bool, vconf_get_dbl, vconf_get_str
 * @par example
 * @code

#include <stdio.h>
#include <vconf.h>

const char *key1_name="db/test/key1";
int main(int argc, char **argv)
{
   int key1_value;

   if(vconf_set_int(key1_name,1))
      fprintf(stderr, "vconf_set_int FAIL\n");
   else
      printf("vconf_set_int OK\n");

   if(vconf_get_int(key1_name, &key1_value))
      fprintf(stderr, "vconf_get_int FAIL\n");
   else
      printf("vconf_get_int OK(key1 value is %d)\n", key1_value);

   return 0;
}
 * @endcode
 */

int vconf_get_int(const char* key, int* intval);

/**
 * This function sets the integer value of given key.
 * @param[in]	in_key	key
 * @param[in]	intval integer value to set (0 is also allowed as a value.)
 * @return 0 on success, -1 on error
 * @pre None
 * @post None
 * @remarks None
 * @see vconf_set_bool(), vconf_set_dbl(), vconf_set_str()
 */

int vconf_set_int(const char* key, int intval);

/**
 * This function gets the string value of given key.
 * \n You have to free this returned value.
 * @param[in]	in_key	key
 * @return allocated pointer of key value on success, NULL on error
 * @pre None
 * @post None
 * @remarks None
 * @see vconf_get_int(), vconf_get_dbl(), vconf_get_bool()
 * @par example
 * @code
   #include <stdio.h>
   #include <vconf.h>

   char *get_str=vconf_get_str("db/test/test1");
   if(get_str) {
      printf("vconf_get_str OK(value = %s)", get_str);
      free(get_str);
   }else
      fprintf(stderr, "vconf_get_str FAIL");
 * @endcode
 */

char* vconf_get_str(const char* key);

/**
 * This function sets the string value of given key.
 * @param[in]	in_key	key
 * @param[in]	strval string value to set
 * @return 0 on success, -1 on error
 * @pre None
 * @post None
 * @remarks None
 * @see vconf_set_bool(), vconf_set_dbl(), vconf_set_int()
 */

int vconf_set_str(const char* key, const char* strval);

/**
 * This function gets Integer value of the keynode.
 * @param[in] keynode The Key
 * @return Integer value, or 0 if no value is obtained
 ** @pre Nome
 * @post None
 * @remarks None
 * @see vconf_notify_key_changed(), vconf_keynode_get_name, vconf_keynode_get_bool, vconf_keynode_get_type,
        vconf_keynode_get_str, vconf_keynode_get_dbl, keynode_t, vconf_t
 */
int vconf_keynode_get_int(keynode_t* keynode);

/**
 * This function adds a change callback for given key,
 * which is called when the key is set or unset.
 * \n Information(#keynode_t) of the key that changed is delivered to #vconf_callback_fn,
 * or if the key is deleted, the @link #keynode_t keynode @endlink has #VCONF_TYPE_NONE as type.
 * \n Multiple vconf_callback_fn functions may exist for one key.
 * \n The callback is issued in the context of the glib main loop.
 * \n WARNING: This callback mechanism DOES NOT GUARANTEE consistency of data chage. For example,
 * When you have a callback for a certain key, assume that two or more processes are trying to
 * change the value of the key competitively. In this case, your callback function will always
 * get 'CURRENT' value, not the value raised the notify that caused run of the callback.  So,
 * do not use vconf callback when competitive write for a key is happening. In such case, use
 * socket-based IPC(dbus or something else) instead.
 *
 * @param[in]   in_key  key
 * @param[in]   cb      callback function
 * @param[in]   user_data    callback data
 * @return 0 on success, -1 on error
 * @pre Nome
 * @post None
 * @remarks None
 * @see vconf_ignore_key_changed
 * @par example
 * @code
 void test_cb(keynode_t *key, void* data)
 {
    switch(vconf_keynode_get_type(key))
    {
       case VCONF_TYPE_INT:
        printf("key = %s, value = %d(int)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_int(key));
        break;
       case VCONF_TYPE_BOOL:
        printf("key = %s, value = %d(bool)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_bool(key));
        break;
       case VCONF_TYPE_DOUBLE:
        printf("key = %s, value = %f(double)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_dbl(key));
        break;
       case VCONF_TYPE_STRING:
        printf("key = %s, value = %s(string)\n",
        vconf_keynode_get_name(key), vconf_keynode_get_str(key));
        break;
       default:
        fprintf(stderr, "Unknown Type(%d)\n", vconf_keynode_get_type(key));
        break;
    }
    return;
 }

 int main()
 {
    int i;
    GMainLoop *event_loop;

    g_type_init();

    vconf_notify_key_changed("db/test/test1", test_cb, NULL);

    event_loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(event_loop);

    vconf_ignore_key_changed("db/test/test1", test_cb);
    return 0;
 }
 * @endcode
 */
int vconf_notify_key_changed(const char* in_key, vconf_callback_fn cb, void* user_data);

/**
 * @brief Removes a change callback for the given key,
 *        which was added by vconf_notify_key_changed().
 *
 * @since_tizen 2.3
 *
 * @param[in]   in_key  The key
 * @param[in]   cb      The callback function
 *
 * @return @c 0 on success,
 *         otherwise @c -1 on error
 *
 * @see vconf_notify_key_changed()
 */
int vconf_ignore_key_changed(const char* in_key, vconf_callback_fn cb);

#endif /* __VCONF_H__ */
