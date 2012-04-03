/*
 * Copyright (C) 2008 The Android Open Source Project
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

#define LOG_TAG "bluedroid"

#include <cutils/log.h>

#include <bluedroid/bluetooth.h>
#include <bluedroid/antradio_power.h>

#define STATE_OFF   0
#define STATE_ON    1

extern int hci_enable();
extern int hci_disable();
extern int hci_is_enabled();

int ant_enable()
{
    LOGV(__FUNCTION__);
    int ret = -1;

    if(hci_enable() < 0) goto out;

    ret = 0;
    ucStateAnt = STATE_ON;

out:
    return ret;
}

int ant_disable()
{
    LOGV(__FUNCTION__);
    int ret = -1;

    if (ucStateBt == STATE_OFF) {
        if (hci_disable() < 0) goto out;

        ret = 0;
    }

    ucStateAnt = STATE_OFF;

out:
    return ret;
}

int ant_is_enabled()
{
    LOGV(__FUNCTION__);
    int ret = 0;

    if (ucStateAnt == STATE_ON)
    {
       ret = hci_is_enabled();
       if (ret == 0) ucStateAnt = STATE_OFF;
    }

    return ret;
}

