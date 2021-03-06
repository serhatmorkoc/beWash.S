#include "../main.h"

Database* gDbCard = new Database();
extern unsigned int summWithCard;

//#pragma region ��������� "RFID ����� �������"
PI_THREAD(RFIDExchangeThread)
{
	Settings* settings = Settings::getInstance();
	if (!settings->threadFlag.IntCommonThread) return (void*)0;
	int lastCardPresent = 0;
	BYTE lastCardNumber[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	Database* db = new Database();
	db->Init(settings);
	gDbCard->Init(&settings->gdatabaseSettings);
	if (db->Open())
		printf("IB ERROR: %s\n", db->lastErrorMessage);
	char myNote[] = "[THREAD] RFID: RFID exchange thread init";
	if (db->Log( 0, DB_EVENT_TYPE_THREAD_INIT, 0, 0, myNote))
		printf("IB ERROR: %s\n", db->lastErrorMessage);

	int rt = 0;
	while (settings->threadFlag.IntCommonThread)
	{
			int timeout = 200;
			while ((settings->busyFlag.RFIDWatch) && (timeout--)) {delay_ms(1);}
			//if ((lastCardPresent == 0) && (status.extDeviceInfo.rfid_cardPresent == 0)) {delay_ms(200); continue;}
			settings->busyFlag.RFIDWatch++;
			//
			// ���������� ��������� ����� RFID
			if (lastCardPresent != status.extDeviceInfo.rfid_cardPresent)
			{
				if (status.extDeviceInfo.rfid_cardPresent)
				{
					lastCardPresent = status.extDeviceInfo.rfid_cardPresent;
					// TODO: ���� ����� ����� ���������
					if (!emptyCardNumber(status.extDeviceInfo.rfid_incomeCardNumber))
					{
						summWithCard = 0;
						memcpy(&status.extDeviceInfo.rfid_prevCardNumber[0], &lastCardNumber[0], 6);
						memcpy(&lastCardNumber[0], &status.extDeviceInfo.rfid_incomeCardNumber[0], 6);
						printf("[RFID] New card inserted: %02X%02X%02X%02X%02X%02X\n",
							status.extDeviceInfo.rfid_incomeCardNumber[0],
							status.extDeviceInfo.rfid_incomeCardNumber[1],
							status.extDeviceInfo.rfid_incomeCardNumber[2],
							status.extDeviceInfo.rfid_incomeCardNumber[3],
							status.extDeviceInfo.rfid_incomeCardNumber[4],
							status.extDeviceInfo.rfid_incomeCardNumber[5]
							);
						// TODO: ��������� ������ �����, ���������, ������
						DB_RFIDCardInfo* cardInfo = &addStatus.db_RFIDCardInfo;
						memset(cardInfo, 0, sizeof(addStatus.db_RFIDCardInfo));
						getCardInfo(status.extDeviceInfo.rfid_incomeCardNumber, cardInfo);
						if (settings->noStoreCardBalance == 0)
							status.intDeviceInfo.money_currentBalance += cardInfo->cardMoney;
						///
						/// Loging in database ...
						/// New card inserted
						///
						char noteBuffer[1024];
						sprintf(noteBuffer, "New card [BAL: %2d, CRD: %lu, $:%d]", status.intDeviceInfo.money_currentBalance, getCardIDFromBytes(status.extDeviceInfo.rfid_incomeCardNumber), (long)cardInfo->cardAllMoney);
						db->Log( 0, DB_EVENT_TYPE_INT_CARD_INSERTED, status.intDeviceInfo.program_currentProgram, status.intDeviceInfo.money_currentBalance, noteBuffer);
						///
						///
					}
				}
				else
				{
					// TODO: ����� ������
					DB_RFIDCardInfo* cardInfo = &addStatus.db_RFIDCardInfo;
					getCardInfo(lastCardNumber, cardInfo);
					if (settings->noStoreCardBalance == 0)
						if ((status.intDeviceInfo.money_currentBalance - cardInfo->cardMoney) != 0)
							setCardMoney(lastCardNumber, status.intDeviceInfo.money_currentBalance - cardInfo->cardMoney);

					///
					/// Loging in database ...
					/// Card is gone
					///
					char noteBuffer[1024];
					sprintf(noteBuffer, "Card is gone [BAL: %2d, CRD: %lu, $:%lu]", status.intDeviceInfo.money_currentBalance, getCardIDFromBytes(lastCardNumber), ((long)cardInfo->cardAllMoney)+(long)summWithCard);
					db->Log( 0, DB_EVENT_TYPE_INT_CARD_GONE, status.intDeviceInfo.program_currentProgram, status.intDeviceInfo.money_currentBalance, noteBuffer);

					if (summWithCard > 0)
					{
						gDbCard->Log( 0, DB_EVENT_TYPE_INT_CARD_ADD_MONEY, getCardIDFromBytes(lastCardNumber), summWithCard, "Money operation with client cards");
						if (settings->UseGlobalDB != 0)
							gDbCard->Log( 1, DB_EVENT_TYPE_INT_CARD_ADD_MONEY, getCardIDFromBytes(lastCardNumber), summWithCard, "Money operation with client cards");
						summWithCard = 0;
					}
					///
					///

					if (settings->noStoreCardBalance == 0)
						status.intDeviceInfo.money_currentBalance = 0;
					memcpy(&status.extDeviceInfo.rfid_prevCardNumber[0], &lastCardNumber[0], 6);
					printf("[RFID] Card is gone [%lu]: %02X%02X%02X%02X%02X%02X\n", getCardIDFromBytes(lastCardNumber),
						status.extDeviceInfo.rfid_incomeCardNumber[0],
						status.extDeviceInfo.rfid_incomeCardNumber[1],
						status.extDeviceInfo.rfid_incomeCardNumber[2],
						status.extDeviceInfo.rfid_incomeCardNumber[3],
						status.extDeviceInfo.rfid_incomeCardNumber[4],
						status.extDeviceInfo.rfid_incomeCardNumber[4]
						);
					memset(&lastCardNumber[0], 0, 6);
					// TODO: ��������� ������ �����, ������
				}
				lastCardPresent = status.extDeviceInfo.rfid_cardPresent;
			}
			else
			{
					// ���� ������� ����� �� �������
					// � ����� ���������
					if ((compareCardNumber(lastCardNumber, status.extDeviceInfo.rfid_incomeCardNumber)) && (!emptyCardNumber(lastCardNumber)) && (!emptyCardNumber(status.extDeviceInfo.rfid_incomeCardNumber)))
					{
						// TODO:����� ��������. ������� ������. �������� �� �����. ��������. ��������� ����� �����
						DB_RFIDCardInfo* cardInfo = &addStatus.db_RFIDCardInfo;
						getCardInfo(lastCardNumber, cardInfo);
						if (settings->noStoreCardBalance == 0)
							if ((status.intDeviceInfo.money_currentBalance - cardInfo->cardMoney) != 0)
								setCardMoney(lastCardNumber, status.intDeviceInfo.money_currentBalance - cardInfo->cardMoney);

						if (summWithCard > 0)
						{
							db->Log( 0, DB_EVENT_TYPE_INT_CARD_ADD_MONEY, getCardIDFromBytes(lastCardNumber), summWithCard, "Money operation with client cards");
							db->Log( 1, DB_EVENT_TYPE_INT_CARD_ADD_MONEY, getCardIDFromBytes(lastCardNumber), summWithCard, "Money operation with client cards");
							summWithCard = 0;
						}

						char noteBuffer[1024];
						sprintf(noteBuffer, "Card is gone (change) [BAL: %2d, CRD: %lu, $:%lu]", status.intDeviceInfo.money_currentBalance, getCardIDFromBytes(lastCardNumber), ((long)cardInfo->cardAllMoney)+(long)summWithCard);
						db->Log( 0, DB_EVENT_TYPE_INT_CARD_GONE, status.intDeviceInfo.program_currentProgram, status.intDeviceInfo.money_currentBalance, noteBuffer);

						if (settings->noStoreCardBalance == 0)
							status.intDeviceInfo.money_currentBalance = 0;

						getCardInfo(status.extDeviceInfo.rfid_incomeCardNumber, cardInfo);
						if (settings->noStoreCardBalance == 0)
							status.intDeviceInfo.money_currentBalance = cardInfo->cardMoney;

						summWithCard = 0;
						sprintf(noteBuffer, "New card (change) [BAL: %2d, CRD: %lu, $:%lu]", status.intDeviceInfo.money_currentBalance, getCardIDFromBytes(status.extDeviceInfo.rfid_incomeCardNumber), (long)cardInfo->cardAllMoney);
						db->Log( 0, DB_EVENT_TYPE_INT_CARD_INSERTED, status.intDeviceInfo.program_currentProgram, status.intDeviceInfo.money_currentBalance, noteBuffer);

						memcpy(status.extDeviceInfo.rfid_prevCardNumber, lastCardNumber, 6);
						memcpy(lastCardNumber, status.extDeviceInfo.rfid_incomeCardNumber, 6);
						lastCardPresent = status.extDeviceInfo.rfid_cardPresent;
					}
			}
			settings->busyFlag.RFIDWatch = 0;
		delay_ms(100);
	}
	db->Close();
	printf("[RFID_EXCHANGE]: Thread ended.\n");
	return (void*)0;
}
//#pragma endregion
