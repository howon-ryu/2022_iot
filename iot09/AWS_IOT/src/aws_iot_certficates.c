/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * Additions Copyright 2016 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n\
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n\
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n\
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n\
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n\
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n\
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n\
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n\
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n\
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n\
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n\
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n\
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n\
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n\
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n\
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n\
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n\
rqXRfboQnoZsG4q5WTP468SQvvG5\n\
-----END CERTIFICATE-----\n"};

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWjCCAkKgAwIBAgIVAKCQn1UXqdSg1gyUsyRc1wC2WUIzMA0GCSqGSIb3DQEB\n\
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n\
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA0MjgxMjAz\n\
NDlaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n\
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDFDY+hMgj8neIRiXJi\n\
K83zvdlJmigIvOKLgJbNFXOckpb4Tv1u+uMRo2YXx4J+T7D4oeIGGjXKBGxHFCqS\n\
p79rG23NDuFvzXpROwbG2CY6okf+aPDjSnbetro7gK2DMOxYj4lYXSRTtfInIevz\n\
B1/WdgASod6x3tskDr/WM5WRlRuDDxUvvLPThJ1y8SnBnKQB+gmAW7/JQVI7Fz2r\n\
C4Tl+TmomuoNXPSfF2mMQCqPrlToY5Z0bGZD0M96Dzb93e//TO84kzklPvbH2cOj\n\
camclLgUjt0F7Cth6Zo67Md6DLz5R+nok6woREJ0JJciKiF3lJuRYSkbCHNBI+Xm\n\
R7j9AgMBAAGjYDBeMB8GA1UdIwQYMBaAFLkInjYdqRQZBsypZofh5/HFViilMB0G\n\
A1UdDgQWBBQ1hiQ2uuI244vJ/bkeizuFzbMMPDAMBgNVHRMBAf8EAjAAMA4GA1Ud\n\
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAINKpS1DaSOO71oxWTQQHEGBP\n\
HEqjPtxiROqjAK1nm8fYvMOtJEsAaY2dGTqF+bwGz07zDyOB8jhj5I/k1fRqAwem\n\
ZAnTgrro/nQXsfc0/a3x/FUmULA5u3/GmjNWnL4JVEAilShX4OvbBFL2dpkKJeyA\n\
GrQsC8v3jYYGFWJF1SCCG+CDPHFrNQJVOhFcCizwDw7e1I5JCmxS5gpbMTwzSaZi\n\
2yerOwfZexa3fAVTs0gR13epBZamiw+FR9ALFeiUxdU2As4K8jLCj/hz2Sy5tJdZ\n\
hECf8zSef2YR7TScxYC0WM+Sh5skI+eDi/HA89dandOu0/aBToIORGzBNrvSIg==\n\
-----END CERTIFICATE-----\n"};

const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEpAIBAAKCAQEAxQ2PoTII/J3iEYlyYivN873ZSZooCLzii4CWzRVznJKW+E79\n\
bvrjEaNmF8eCfk+w+KHiBho1ygRsRxQqkqe/axttzQ7hb816UTsGxtgmOqJH/mjw\n\
40p23ra6O4CtgzDsWI+JWF0kU7XyJyHr8wdf1nYAEqHesd7bJA6/1jOVkZUbgw8V\n\
L7yz04SdcvEpwZykAfoJgFu/yUFSOxc9qwuE5fk5qJrqDVz0nxdpjEAqj65U6GOW\n\
dGxmQ9DPeg82/d3v/0zvOJM5JT72x9nDo3GpnJS4FI7dBewrYemaOuzHegy8+Ufp\n\
6JOsKERCdCSXIiohd5SbkWEpGwhzQSPl5ke4/QIDAQABAoIBADRyVo8dxRyPXRMz\n\
1PjiFc/Q8NtRJ2Sj+VwN3pU5J2s97OasB3IZXoRcTBj6JfY+eajDVWgwY66gHL2S\n\
VX5xHVaBl2jjlAbw1qR2JGiaMRqcBLNm9O5Z7Gd8lPavWf837z/m/DRDnh6Vp5zY\n\
v3cQuGZZQ82xvZbz7LmdH1wAoMd9Q36XY0hChhy/DghF2uBuPVh9eY5NMindOAR1\n\
ThxtIAVRNu+3S6iRa2udSL3+hMLwNMLTsTCwVEmPOsmiIswKBy8rR2SLO4ZrhgNi\n\
BmD6YeaVXy1cp++BvqX/5UDdLOKgpTSrcRqNiGt69ySF/kSQ9BmQQ3kPJmDGxl7+\n\
9XzLFFUCgYEA7CpEwpbgAIeThoylVo8KfOlQLEfveQrtlz0xxVoVa6nPFsbR9ZxR\n\
Sroe+cnpXjj6DB6yzD5427FSWC/BsnW641AtwQOTnzVYTqFiV5vtn8JpJxk3z5bc\n\
h8KLGxcyp31Cam9tKImDSW/CoIkEm7QjXttxBxT5b82r0Lxga95mB+cCgYEA1ZpZ\n\
9lE3A2k3+sZcr5pnkK6hHcj5ZcS4aX+lPOGBZnDg8QM+Y8OOE/1LJbo4HQ1SpZYJ\n\
q3VJdQdpwKUQCDSlRQ2Z+/FrUyw4XlgZ92GpXL6xJ3os/FGcPI3aK7U46vbw+4DC\n\
pTjd4na0341Tg5MFtVl8/OsV0sCKMCnltaZdC3sCgYEAhUxqWScNsl7T3wr9u7ir\n\
I8wRC51ixoBrkITi1dC97HIBSIraMXaUz8fz+euEhEFGqZaeNvhAAUi6ALqb6t3W\n\
qb00xg/9v8w9VsxylJ6XZig2b/Ik9U/ik+Iz4Auc9LqXxTm1dD8B0m55fWE5L6Vi\n\
nYTg7C1jiT6ebwgUqG30SxsCgYBzRiFWtO2jgZ0cUQCkJAfQJO3+TP+K1GdRR/m8\n\
qVZUGobKip2Y6Wg7kW6EpcKyqwX3JsmBJoLGDYIc3PeR9hda9MQtG1R4Rl0FTTZ2\n\
MtZbnu2sCFtOsBxI8aTUAbD93NagZBSnZdEY7kceff6b+zQRcoHpXFUir5Xj+Dhn\n\
l6iPEQKBgQDXhUke0USZ/+iD81oluN94B48DDByn4LW5xo9YNYrgMeHjqnnF9Nwz\n\
DhT2zpPmcoxuNTO4Nu145/WWhOlhxPxeZLxavCL0Gj6sIf1MZP5tfECUH/3nZIHf\n\
MzzEs+iNigaX/hVK/qroCBhhFdlNHHez8/yus4bYBVDWClTuIvR5cA==\n\
-----END RSA PRIVATE KEY-----\n"};


#ifdef __cplusplus
}
#endif
