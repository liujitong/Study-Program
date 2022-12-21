#include "sysInclude.h"  //����Rivernet2000 ϵͳ����ṩ�Ŀ⺯��
extern void ip_DiscardPkt(char* pBuffer,int type); //������
extern void ip_SendtoLower(char*pBuffer,int length); //�����²�
extern void ip_SendtoUp(char *pBuffer,int length); //�����ϲ�
extern unsigned int getIpv4Address(); 
// implemented by students 
int stud_ip_recv(char *pBuffer,unsigned short length)  //�Լ�ʵ�ֵı���Ipv4���ݰ����պ���
{ 
	//��ȡipͷ��Ϣ 
	int version = pBuffer[0] >> 4; 
	int headlength = pBuffer[0] & 0xf; 
	int timetolive = (int)pBuffer[8]; 
	int headerChecksum = ntohs(*(short unsigned int*)(pBuffer+10)); 
	int destinationAddress = ntohl(*(unsigned int*)(pBuffer+16)); 
	if (version != 4) //���version 
	{ 
	ip_DiscardPkt(pBuffer,STUD_IP_TEST_VERSION_ERROR); 
	return 1; 
	}
	if (headlength < 5) //���IHL 
	{ 
	ip_DiscardPkt(pBuffer,STUD_IP_TEST_HEADLEN_ERROR); 
	return 1; 
	} 
	if (timetolive == 0) //���TTL 
	{ 
	ip_DiscardPkt(pBuffer,STUD_IP_TEST_TTL_ERROR); 
	return 1; 
	} 
	//���Ŀ�ĵ�ַ�ͱ�����ַ�Ƿ���ͬ 
	if (destinationAddress != getIpv4Address() && destinationAddress != 0xffffff) 
	{ 
	ip_DiscardPkt(pBuffer,STUD_IP_TEST_DESTINATION_ERROR); 
	return 1; 
	} 
	int sum = 0; 
	unsigned short int localCheckSum = 0; 
	unsigned short int field; 
	int offset; 
	for(int i = 1;i <= headlength*2; i++) //����У��� 
	{ 
	offset = (i-1)*2; 
	if(i != 6) 
	{ 
	field = (pBuffer[offset])<<8; 
	field += pBuffer[offset+1]; 
	sum += field; 
	sum %= 65535; 
	} 
	} 
	localCheckSum = 0xffff - (unsigned short int)sum; 
	if(localCheckSum != headerChecksum) //����У��� 
	{ 
	ip_DiscardPkt(pBuffer,STUD_IP_TEST_CHECKSUM_ERROR); 
	return 1; 
	} 

	ip_SendtoUp(pBuffer,length); 
	return 0; 
} 
int stud_ip_Upsend(char *pBuffer,unsigned short len,unsigned int srcAddr, 
unsigned int dstAddr,byte protocol,byte ttl) 
{ 
	char *sendBuffer = new char(len + 20); 
	memset(sendBuffer, 0, len+20); 
	//�������IPͷ��Ϣ 
	sendBuffer[0] = 0x45; 
	unsigned short int totallen = htons(len + 20); 
	memcpy(sendBuffer + 2, &totallen, sizeof(unsigned short int)); 
	sendBuffer[8] = ttl; 
	sendBuffer[9] = protocol; 
	unsigned int src = htonl(srcAddr); 
	unsigned int dis = htonl(dstAddr); 
	memcpy(sendBuffer + 12, &src, sizeof(unsigned int)); 
	memcpy(sendBuffer + 16, &dis, sizeof(unsigned int)); 

	int sum = 0; 
	unsigned short int localCheckSum = 0; 
	for(int i = 0;i < 10;i ++) 
	{ 
	sum = sum + (sendBuffer[i*2]<<8) + (sendBuffer[i*2+1]); 
	sum %= 65535; 
	} 
	localCheckSum = htons(0xffff - (unsigned short int)sum); 

	memcpy(sendBuffer + 10, &localCheckSum, sizeof(unsigned short int)); 
	memcpy(sendBuffer + 20, pBuffer, len); 
	//���� 
	ip_SendtoLower(sendBuffer,len+20); 
	return 0;
}
