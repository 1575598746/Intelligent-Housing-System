#include "qmessagethread.h"
#include "malloc.h"


QMessageThread::QMessageThread(Posix_QextSerialPort *pCom, QObject *parent) :
    m_com(pCom),QThread(parent)
{
    m_com->setBaudRate(BAUD115200);
    m_com->setDataBits(DATA_8);
    m_com->setStopBits(STOP_1);
    m_com->setParity(PAR_NONE);

    m_com->setFlowControl(FLOW_OFF);
    m_com->setTimeout(10);

    if(m_com->open(QIODevice::ReadWrite)){
        qDebug("open ttyS1");

        char str[106] = "at\rate1\rat+chfa=1\rat+clvl=100\rat+cmic=1,10\rat+cmgf=1\rat+clip=1\rat+cscs=\"GSM\"\rat+clip=1\rat+cnmi=2,1,0,0,0\r";
        if(m_com != NULL){
            m_com->write(str, 3);
            usleep(20);
            m_com->write(str + 3, 5);
            usleep(20);
            m_com->write(str + 8, 10);
            usleep(20);
            m_com->write(str + 18, 12);
            usleep(20);
            m_com->write(str + 30, 13);
            usleep(20);
            m_com->write(str + 43, 10);
            usleep(20);
            m_com->write(str + 53, 10);
            usleep(20);
            m_com->write(str + 63, 14);
            usleep(20);
            m_com->write(str + 77, 10);
            usleep(20);
            m_com->write(str + 87, 18);
            usleep(20);
        }
    }

//    callnumber = call;
//    smstext = sms;


}


void QMessageThread::run()
{
//    const char * SM = "+CMTI: \"SM\",";
//    char buffer[256];
//    char read_buf[512];
//    number = (char *)malloc(64 * sizeof(char));
//    text = (char *)malloc(512 * sizeof(char));
//    int size = -1;
//    int i;

//    while(1){
//        i = 0;
//        memset(buffer, 0, sizeof(buffer));

//        while(size = m_com->read(buffer + i, 1)){
//            qDebug("%c", buffer[i]);
//            ++i;
//        }

//        usleep(1000 * 300);

//        char * index = NULL;
//        qDebug(buffer);
//        if(strstr(buffer, SM)){
//            memset(read_buf, 0, sizeof(read_buf));
//            index = strchr(buffer, ',');
//            index ++;

//            m_com->write("at+cmgr=");
//            usleep(20);
//            m_com->write(index, strlen(index));
//            usleep(1000 * 300);

//            int j = 0;

//            while(size = m_com->read(read_buf + j, 1)){
//                ++j;
//            }
//            if(j > 0){
//                for(int i = 0; i < j; ++i){
//                    printf("%c", read_buf[i]);
//                    fflush(stdout);
//                }

//                usleep(1000 * 300);
//                int num_start_index = 0;
//                int num_end_index = 0;
//                int text_start_index = 0;
//                int text_end_index = 0;

//                while(read_buf[num_start_index ++] != ',');
//                num_start_index += 2;
//                num_end_index = num_start_index;
//                while(read_buf[num_end_index ++] != '\"');
//                num_end_index -= 2;

//                //char num_buf[64];
//                memset(number, 0, sizeof(number));
//                int k = 0;
//                for(int i = num_start_index; i <= num_end_index; ++i){
//                    printf("%c", read_buf[i]);
//                    number[k++] = read_buf[i];
//                    number[k] = '\0';
//                    fflush(stdout);
//                }

//                text_start_index = j;
//                while(read_buf[--text_start_index] != ':');
//                text_start_index += 3;

//                text_end_index = text_start_index;
//                while(read_buf[text_end_index++] != '\r');
//                --text_end_index;

//                k = 0;
//                //char text_buf[512];
//                memset(text, 0, sizeof(text));
//                for(int i = text_start_index; i <= text_end_index; i++){
//                    printf("%c", read_buf[i]);

//                    text[k++] = read_buf[i];
//                    text[k] = '\0';
//                    fflush(stdout);
//                }
//            }
//        }
//    }
    char buffer[15] = {0};
    char str[3] = {0};
    char readBuf[1024] = {0};
    number = (char *)malloc(64 * sizeof(char));
    text = (char *)malloc(512 * sizeof(char));
    int endLOC;
    int numBegin;
    int numEnd;
    int textEnd;
    int textBegin;
    int i;
    while(1){
        if(m_com != NULL){
            int size = m_com->read(buffer,1);
            if(buffer[0] == '+'){
                size = m_com->read(buffer + 1, 10);
                if(size > 0){
                    buffer[11] = '\0';
                    if(strcmp("+CMTI:\”SM\”,",buffer) == 0){
                        //char str[3] = {0};
                        size = m_com->read(str,2);
                        if(size > 0){
                            str[2] = '\0';
                            if(str[1] >= '0' && str[1] <= '9'){
                                char writeBuf[10] = {'a','t','+','c','m','g','r','=',str[0],str[1]};
                                size = m_com->write(writeBuf);
                                usleep(50);
                            }
                            else{
                                char writeBuf[9] = {'a','t','+','c','m','g','r','=',str[0]};
                                size = m_com->write(writeBuf);
                                usleep(50);
                            }
                            m_com->read(readBuf,1024);
                            for(i = 0; i < 1024; i++){
                                if(readBuf[i] == 'O' && readBuf[i + 1] == 'K'){
                                    endLOC = i;
                                }
                            }
                            for(i = 0; i < 1024; i++){
                                if(readBuf[i] == '\"' && readBuf[i+1] == ',' && readBuf[i+2] == '\"'){
                                    numBegin = i + 3;
                                }
                                for(i = numBegin; i < 1024; i++){
                                    if(readBuf[i] == '\"'){
                                        numEnd = i;
                                    }
                                }
                            }
                            int k = 0;
                            for(i = numBegin; i < numEnd; i++){
                                number[k++] = readBuf[i];
                                number[k] = '\0';
                            }
                            for(i = endLOC; i > 0; i--){
                                if(readBuf[i] == '\n'&&readBuf[i-1]=='\r'&&readBuf[i-2]=='\n'&&readBuf[i-3]=='\r'){
                                    textEnd = i - 4;
                                }
                            }
                            for(i = textEnd; i > 0; i--){
                                if(readBuf[i] == ':'){
                                    textBegin = i + 1;
                                }
                            }
                            k = 0;
                            for(i = textBegin; i < textEnd; i++){
                                text[k++] = readBuf[i];
                                text[k] = '\0';
                            }
                            }
                        }
                    }
                }
            }
        }
    }
//}

//"at\rate0\rat+chfa=1\rat+clvl=100\rat+cmic=1,10\rat+cmgf=1\rat+clip=1\rat+cscs=\"GSM\"\rat+clip=1\rat+cnmi=2,1,0,0,0\r"
//"atd13800000000;\r"


void QMessageThread::Call(QString number)
{
//    if(a == 1)
//    {
        //char str[17] = "atd13354283913;\r";
        m_com->write("atd");
        usleep(50);
        m_com->write(number.toStdString().c_str());
        usleep(50);
        m_com->write(";\r");
        usleep(50);
        qDebug("Call now");
        qDebug(number.toStdString().c_str());
//    }
}

void QMessageThread::SendSMS(QString number, QString text){
//    if(a == 1){
    char ctl[] = {26,0};
    if(m_com != NULL){
        m_com->write("at+cmgs=");
        m_com->write("\"");
        m_com->write(number.toStdString().c_str());
        m_com->write("\"");
        m_com->write(";\r");
        usleep(300 * 1000);
        m_com->write(text.toStdString().c_str());
        m_com->write(ctl,1);
        qDebug("send message");
        qDebug(number.toStdString().c_str());
        qDebug(text.toStdString().c_str());
//    }
    }
}


void QMessageThread::call_119(bool a){
    if(1 == a){
        m_com->write("atd");
        usleep(50);
        m_com->write("119");
        usleep(50);
        m_com->write(";\r");
        usleep(50);
        qDebug("Call 119");
    }
}

void QMessageThread::call_120(bool a){
    if(1 == a){
        m_com->write("atd");
        usleep(50);
        m_com->write("120");
        usleep(50);
        m_com->write(";\r");
        usleep(50);
        qDebug("Call 120");
    }
}

void QMessageThread::call_110(bool a){
    if(1 == a){
        m_com->write("atd");
        usleep(50);
        m_com->write("110");
        usleep(50);
        m_com->write(";\r");
        usleep(50);
        qDebug("Call 110");
    }
}

void QMessageThread::call_family(QString number){

        m_com->write("atd");
        usleep(50);
        m_com->write(number.toStdString().c_str());
        usleep(50);
        m_com->write(";\r");
        usleep(50);
        qDebug(number.toStdString().c_str());

}

void QMessageThread::call_friends(QString number){
    m_com->write("atd");
    usleep(50);
    m_com->write(number.toStdString().c_str());
    usleep(50);
    m_com->write(";\r");
    usleep(50);
    qDebug(number.toStdString().c_str());
}

void QMessageThread::call_colleagues(QString number){
    m_com->write("atd");
    usleep(50);
    m_com->write(number.toStdString().c_str());
    usleep(50);
    m_com->write(";\r");
    usleep(50);
    qDebug(number.toStdString().c_str());
}
