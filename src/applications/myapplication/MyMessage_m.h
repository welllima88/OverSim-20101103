//
// Generated file, do not edit! Created by opp_msgc 4.1 from applications/myapplication/MyMessage.msg.
//

#ifndef _MYMESSAGE_M_H_
#define _MYMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <TransportAddress.h>
// }}



/**
 * Enum generated from <tt>applications/myapplication/MyMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum MessageType 
 * {
 *     MYMSG_PING = 1;           
 *     MYMSG_PONG = 2;           
 * }
 * </pre>
 */
enum MessageType {
    MYMSG_PING = 1,
    MYMSG_PONG = 2
};

/**
 * Class generated from <tt>applications/myapplication/MyMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet MyMessage 
 * {
 *     int type enum(MessageType);      
 *     TransportAddress senderAddress;  
 * }
 * </pre>
 */
class MyMessage : public ::cPacket
{
  protected:
    int type_var;
    ::TransportAddress senderAddress_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MyMessage&);

  public:
    MyMessage(const char *name=NULL, int kind=0);
    MyMessage(const MyMessage& other);
    virtual ~MyMessage();
    MyMessage& operator=(const MyMessage& other);
    virtual MyMessage *dup() const {return new MyMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getType() const;
    virtual void setType(int type_var);
    virtual TransportAddress& getSenderAddress();
    virtual const TransportAddress& getSenderAddress() const {return const_cast<MyMessage*>(this)->getSenderAddress();}
    virtual void setSenderAddress(const TransportAddress& senderAddress_var);
};

inline void doPacking(cCommBuffer *b, MyMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MyMessage& obj) {obj.parsimUnpack(b);}


#endif // _MYMESSAGE_M_H_
