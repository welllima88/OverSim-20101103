//
// Generated file, do not edit! Created by opp_msgc 4.1 from overlay/pastry/PastryMessage.msg.
//

#ifndef _PASTRYMESSAGE_M_H_
#define _PASTRYMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <IPvXAddress.h>
#include <NodeHandle.h>
#include <OverlayKey.h>
#include <CommonMessages_m.h>


static const int PASTRYTYPE_L = 8;
static const int PASTRYSTATETYPE_L = 8;
static const int PASTRYREQUESTTYPE_L = 0;
static const int LASTHOPFLAG_L = 8;
static const int TIMESTAMP_L = 32;
static const int PASTRYFINDNODEEXTDATA_L = NODEHANDLE_L + HOPCOUNT_L;

#define PASTRY_L(msg) (BASEOVERLAY_L(msg) + PASTRYTYPE_L)
#define PASTRYJOIN_L(msg) (PASTRY_L(msg) + TRANSPORTADDRESS_L + HOPCOUNT_L)
#define PASTRYREQ_L(msg) (PASTRY_L(msg) + TRANSPORTADDRESS_L + PASTRYREQUESTTYPE_L)
#define PASTRYSTATE_L(msg) (PASTRY_L(msg) + TRANSPORTADDRESS_L \
        + NODEHANDLE_L * \
        (msg->getRoutingTableArraySize() + msg->getLeafSetArraySize() \
        + msg->getNeighborhoodSetArraySize()) + ARRAYSIZE_L + HOPCOUNT_L + \
        LASTHOPFLAG_L + TIMESTAMP_L)
#define PASTRYNEWLEAFS_L(msg) (msg->getLeafsArraySize() * NODEHANDLE_L + \
        ARRAYSIZE_L)
#define PASTRYLEAFSET_L(msg) (PASTRY_L(msg) + TRANSPORTADDRESS_L \
        + NODEHANDLE_L * msg->getLeafSetArraySize() + ARRAYSIZE_L)
#define PASTRYRTREQ_L(msg) (PASTRY_L(msg) + TRANSPORTADDRESS_L)
#define PASTRYRTABLE_L(msg) (PASTRY_L(msg) + TRANSPORTADDRESS_L \
        + NODEHANDLE_L * msg->getRoutingTableArraySize() + ARRAYSIZE_L)
// }}



/**
 * Enum generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum PastryMsgType
 * {
 *     PASTRY_MSG_STD = 0;
 *     PASTRY_MSG_JOIN = 1;
 *     PASTRY_MSG_STATE = 2;
 *     PASTRY_MSG_REQ = 3;
 *     PASTRY_MSG_LEAFSET = 4;	
 *     PASTRY_MSG_ROWREQ = 5;
 *     PASTRY_MSG_RROW = 6;
 *     PASTRY_MSG_LEAFSET_PULL = 7;
 *     PASTRY_REQ_REPAIR = 8;
 *     PASTRY_REQ_STATE = 9;
 *     PASTRY_REQ_LEAFSET = 10;
 * }
 * </pre>
 */
enum PastryMsgType {
    PASTRY_MSG_STD = 0,
    PASTRY_MSG_JOIN = 1,
    PASTRY_MSG_STATE = 2,
    PASTRY_MSG_REQ = 3,
    PASTRY_MSG_LEAFSET = 4,
    PASTRY_MSG_ROWREQ = 5,
    PASTRY_MSG_RROW = 6,
    PASTRY_MSG_LEAFSET_PULL = 7,
    PASTRY_REQ_REPAIR = 8,
    PASTRY_REQ_STATE = 9,
    PASTRY_REQ_LEAFSET = 10
};

/**
 * Enum generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum PastryStateMsgType
 * {
 *     PASTRY_STATE_STD = 0;
 *     PASTRY_STATE_JOIN = 1;
 *     PASTRY_STATE_MINJOIN = 2;
 *     PASTRY_STATE_UPDATE = 3;
 *     PASTRY_STATE_REPAIR = 4;
 *     PASTRY_STATE_JOINUPDATE = 5;
 * }
 * </pre>
 */
enum PastryStateMsgType {
    PASTRY_STATE_STD = 0,
    PASTRY_STATE_JOIN = 1,
    PASTRY_STATE_MINJOIN = 2,
    PASTRY_STATE_UPDATE = 3,
    PASTRY_STATE_REPAIR = 4,
    PASTRY_STATE_JOINUPDATE = 5
};

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryMessage extends BaseOverlayMessage
 * {
 *         int pastryMsgType = PASTRY_MSG_STD;    
 * }
 * </pre>
 */
class PastryMessage : public ::BaseOverlayMessage
{
  protected:
    int pastryMsgType_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryMessage&);

  public:
    PastryMessage(const char *name=NULL, int kind=0);
    PastryMessage(const PastryMessage& other);
    virtual ~PastryMessage();
    PastryMessage& operator=(const PastryMessage& other);
    virtual PastryMessage *dup() const {return new PastryMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getPastryMsgType() const;
    virtual void setPastryMsgType(int pastryMsgType_var);
};

inline void doPacking(cCommBuffer *b, PastryMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryJoinMessage extends PastryMessage
 * {
 *         TransportAddress sendStateTo = TransportAddress::UNSPECIFIED_NODE;    
 * }
 * </pre>
 */
class PastryJoinMessage : public ::PastryMessage
{
  protected:
    ::TransportAddress sendStateTo_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryJoinMessage&);

  public:
    PastryJoinMessage(const char *name=NULL, int kind=0);
    PastryJoinMessage(const PastryJoinMessage& other);
    virtual ~PastryJoinMessage();
    PastryJoinMessage& operator=(const PastryJoinMessage& other);
    virtual PastryJoinMessage *dup() const {return new PastryJoinMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual TransportAddress& getSendStateTo();
    virtual const TransportAddress& getSendStateTo() const {return const_cast<PastryJoinMessage*>(this)->getSendStateTo();}
    virtual void setSendStateTo(const TransportAddress& sendStateTo_var);
};

inline void doPacking(cCommBuffer *b, PastryJoinMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryJoinMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryStateMessage extends PastryMessage
 * {
 *         int pastryStateMsgType = PASTRY_STATE_STD;    
 *         NodeHandle sender = NodeHandle::UNSPECIFIED_NODE;    
 *         NodeHandle routingTable[];    
 *         NodeHandle leafSet[];    
 *         NodeHandle neighborhoodSet[];    
 *         int joinHopCount = 0;    
 *         bool lastHop = false;    
 *         simtime_t timestamp;    
 * }
 * </pre>
 */
class PastryStateMessage : public ::PastryMessage
{
  protected:
    int pastryStateMsgType_var;
    ::NodeHandle sender_var;
    ::NodeHandle *routingTable_var; // array ptr
    unsigned int routingTable_arraysize;
    ::NodeHandle *leafSet_var; // array ptr
    unsigned int leafSet_arraysize;
    ::NodeHandle *neighborhoodSet_var; // array ptr
    unsigned int neighborhoodSet_arraysize;
    int joinHopCount_var;
    bool lastHop_var;
    simtime_t timestamp_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryStateMessage&);

  public:
    PastryStateMessage(const char *name=NULL, int kind=0);
    PastryStateMessage(const PastryStateMessage& other);
    virtual ~PastryStateMessage();
    PastryStateMessage& operator=(const PastryStateMessage& other);
    virtual PastryStateMessage *dup() const {return new PastryStateMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getPastryStateMsgType() const;
    virtual void setPastryStateMsgType(int pastryStateMsgType_var);
    virtual NodeHandle& getSender();
    virtual const NodeHandle& getSender() const {return const_cast<PastryStateMessage*>(this)->getSender();}
    virtual void setSender(const NodeHandle& sender_var);
    virtual void setRoutingTableArraySize(unsigned int size);
    virtual unsigned int getRoutingTableArraySize() const;
    virtual NodeHandle& getRoutingTable(unsigned int k);
    virtual const NodeHandle& getRoutingTable(unsigned int k) const {return const_cast<PastryStateMessage*>(this)->getRoutingTable(k);}
    virtual void setRoutingTable(unsigned int k, const NodeHandle& routingTable_var);
    virtual void setLeafSetArraySize(unsigned int size);
    virtual unsigned int getLeafSetArraySize() const;
    virtual NodeHandle& getLeafSet(unsigned int k);
    virtual const NodeHandle& getLeafSet(unsigned int k) const {return const_cast<PastryStateMessage*>(this)->getLeafSet(k);}
    virtual void setLeafSet(unsigned int k, const NodeHandle& leafSet_var);
    virtual void setNeighborhoodSetArraySize(unsigned int size);
    virtual unsigned int getNeighborhoodSetArraySize() const;
    virtual NodeHandle& getNeighborhoodSet(unsigned int k);
    virtual const NodeHandle& getNeighborhoodSet(unsigned int k) const {return const_cast<PastryStateMessage*>(this)->getNeighborhoodSet(k);}
    virtual void setNeighborhoodSet(unsigned int k, const NodeHandle& neighborhoodSet_var);
    virtual int getJoinHopCount() const;
    virtual void setJoinHopCount(int joinHopCount_var);
    virtual bool getLastHop() const;
    virtual void setLastHop(bool lastHop_var);
    virtual simtime_t getTimestamp() const;
    virtual void setTimestamp(simtime_t timestamp_var);
};

inline void doPacking(cCommBuffer *b, PastryStateMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryStateMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryFindNodeExtData
 * {
 *         TransportAddress sendStateTo = TransportAddress::UNSPECIFIED_NODE;    
 *         int joinHopCount = 0;    
 * }
 * </pre>
 */
class PastryFindNodeExtData : public ::cPacket
{
  protected:
    ::TransportAddress sendStateTo_var;
    int joinHopCount_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryFindNodeExtData&);

  public:
    PastryFindNodeExtData(const char *name=NULL, int kind=0);
    PastryFindNodeExtData(const PastryFindNodeExtData& other);
    virtual ~PastryFindNodeExtData();
    PastryFindNodeExtData& operator=(const PastryFindNodeExtData& other);
    virtual PastryFindNodeExtData *dup() const {return new PastryFindNodeExtData(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual TransportAddress& getSendStateTo();
    virtual const TransportAddress& getSendStateTo() const {return const_cast<PastryFindNodeExtData*>(this)->getSendStateTo();}
    virtual void setSendStateTo(const TransportAddress& sendStateTo_var);
    virtual int getJoinHopCount() const;
    virtual void setJoinHopCount(int joinHopCount_var);
};

inline void doPacking(cCommBuffer *b, PastryFindNodeExtData& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryFindNodeExtData& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryNewLeafsMessage
 * {
 *         NodeHandle leafs[];    
 * }
 * </pre>
 */
class PastryNewLeafsMessage : public ::cPacket
{
  protected:
    ::NodeHandle *leafs_var; // array ptr
    unsigned int leafs_arraysize;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryNewLeafsMessage&);

  public:
    PastryNewLeafsMessage(const char *name=NULL, int kind=0);
    PastryNewLeafsMessage(const PastryNewLeafsMessage& other);
    virtual ~PastryNewLeafsMessage();
    PastryNewLeafsMessage& operator=(const PastryNewLeafsMessage& other);
    virtual PastryNewLeafsMessage *dup() const {return new PastryNewLeafsMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setLeafsArraySize(unsigned int size);
    virtual unsigned int getLeafsArraySize() const;
    virtual NodeHandle& getLeafs(unsigned int k);
    virtual const NodeHandle& getLeafs(unsigned int k) const {return const_cast<PastryNewLeafsMessage*>(this)->getLeafs(k);}
    virtual void setLeafs(unsigned int k, const NodeHandle& leafs_var);
};

inline void doPacking(cCommBuffer *b, PastryNewLeafsMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryNewLeafsMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastrySendState
 * {
 *         TransportAddress dest = TransportAddress::UNSPECIFIED_NODE;
 * }
 * </pre>
 */
class PastrySendState : public ::cPacket
{
  protected:
    ::TransportAddress dest_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastrySendState&);

  public:
    PastrySendState(const char *name=NULL, int kind=0);
    PastrySendState(const PastrySendState& other);
    virtual ~PastrySendState();
    PastrySendState& operator=(const PastrySendState& other);
    virtual PastrySendState *dup() const {return new PastrySendState(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual TransportAddress& getDest();
    virtual const TransportAddress& getDest() const {return const_cast<PastrySendState*>(this)->getDest();}
    virtual void setDest(const TransportAddress& dest_var);
};

inline void doPacking(cCommBuffer *b, PastrySendState& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastrySendState& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryLeafsetMessage extends PastryMessage
 * {
 *         NodeHandle sender = NodeHandle::UNSPECIFIED_NODE;
 *         TransportAddress sendStateTo = TransportAddress::UNSPECIFIED_NODE;
 *         NodeHandle leafSet[];
 *         simtime_t timestamp = 0;
 * }
 * </pre>
 */
class PastryLeafsetMessage : public ::PastryMessage
{
  protected:
    ::NodeHandle sender_var;
    ::TransportAddress sendStateTo_var;
    ::NodeHandle *leafSet_var; // array ptr
    unsigned int leafSet_arraysize;
    simtime_t timestamp_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryLeafsetMessage&);

  public:
    PastryLeafsetMessage(const char *name=NULL, int kind=0);
    PastryLeafsetMessage(const PastryLeafsetMessage& other);
    virtual ~PastryLeafsetMessage();
    PastryLeafsetMessage& operator=(const PastryLeafsetMessage& other);
    virtual PastryLeafsetMessage *dup() const {return new PastryLeafsetMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual NodeHandle& getSender();
    virtual const NodeHandle& getSender() const {return const_cast<PastryLeafsetMessage*>(this)->getSender();}
    virtual void setSender(const NodeHandle& sender_var);
    virtual TransportAddress& getSendStateTo();
    virtual const TransportAddress& getSendStateTo() const {return const_cast<PastryLeafsetMessage*>(this)->getSendStateTo();}
    virtual void setSendStateTo(const TransportAddress& sendStateTo_var);
    virtual void setLeafSetArraySize(unsigned int size);
    virtual unsigned int getLeafSetArraySize() const;
    virtual NodeHandle& getLeafSet(unsigned int k);
    virtual const NodeHandle& getLeafSet(unsigned int k) const {return const_cast<PastryLeafsetMessage*>(this)->getLeafSet(k);}
    virtual void setLeafSet(unsigned int k, const NodeHandle& leafSet_var);
    virtual simtime_t getTimestamp() const;
    virtual void setTimestamp(simtime_t timestamp_var);
};

inline void doPacking(cCommBuffer *b, PastryLeafsetMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryLeafsetMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryRoutingRowRequestMessage extends PastryMessage
 * {
 *         TransportAddress sendStateTo = TransportAddress::UNSPECIFIED_NODE;
 *         int row;
 * 
 * }
 * </pre>
 */
class PastryRoutingRowRequestMessage : public ::PastryMessage
{
  protected:
    ::TransportAddress sendStateTo_var;
    int row_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryRoutingRowRequestMessage&);

  public:
    PastryRoutingRowRequestMessage(const char *name=NULL, int kind=0);
    PastryRoutingRowRequestMessage(const PastryRoutingRowRequestMessage& other);
    virtual ~PastryRoutingRowRequestMessage();
    PastryRoutingRowRequestMessage& operator=(const PastryRoutingRowRequestMessage& other);
    virtual PastryRoutingRowRequestMessage *dup() const {return new PastryRoutingRowRequestMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual TransportAddress& getSendStateTo();
    virtual const TransportAddress& getSendStateTo() const {return const_cast<PastryRoutingRowRequestMessage*>(this)->getSendStateTo();}
    virtual void setSendStateTo(const TransportAddress& sendStateTo_var);
    virtual int getRow() const;
    virtual void setRow(int row_var);
};

inline void doPacking(cCommBuffer *b, PastryRoutingRowRequestMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryRoutingRowRequestMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryRoutingRowMessage extends PastryMessage
 * {
 *         NodeHandle sender = NodeHandle::UNSPECIFIED_NODE;
 *         NodeHandle routingTable[];
 *         int row;
 *         simtime_t timestamp = 0;
 * }
 * </pre>
 */
class PastryRoutingRowMessage : public ::PastryMessage
{
  protected:
    ::NodeHandle sender_var;
    ::NodeHandle *routingTable_var; // array ptr
    unsigned int routingTable_arraysize;
    int row_var;
    simtime_t timestamp_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryRoutingRowMessage&);

  public:
    PastryRoutingRowMessage(const char *name=NULL, int kind=0);
    PastryRoutingRowMessage(const PastryRoutingRowMessage& other);
    virtual ~PastryRoutingRowMessage();
    PastryRoutingRowMessage& operator=(const PastryRoutingRowMessage& other);
    virtual PastryRoutingRowMessage *dup() const {return new PastryRoutingRowMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual NodeHandle& getSender();
    virtual const NodeHandle& getSender() const {return const_cast<PastryRoutingRowMessage*>(this)->getSender();}
    virtual void setSender(const NodeHandle& sender_var);
    virtual void setRoutingTableArraySize(unsigned int size);
    virtual unsigned int getRoutingTableArraySize() const;
    virtual NodeHandle& getRoutingTable(unsigned int k);
    virtual const NodeHandle& getRoutingTable(unsigned int k) const {return const_cast<PastryRoutingRowMessage*>(this)->getRoutingTable(k);}
    virtual void setRoutingTable(unsigned int k, const NodeHandle& routingTable_var);
    virtual int getRow() const;
    virtual void setRow(int row_var);
    virtual simtime_t getTimestamp() const;
    virtual void setTimestamp(simtime_t timestamp_var);
};

inline void doPacking(cCommBuffer *b, PastryRoutingRowMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryRoutingRowMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/pastry/PastryMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet PastryRequestMessage extends PastryMessage
 * {
 *         TransportAddress sendStateTo = TransportAddress::UNSPECIFIED_NODE;    
 *         int pastryReqType = PASTRY_MSG_STD;    
 * }
 * </pre>
 */
class PastryRequestMessage : public ::PastryMessage
{
  protected:
    ::TransportAddress sendStateTo_var;
    int pastryReqType_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PastryRequestMessage&);

  public:
    PastryRequestMessage(const char *name=NULL, int kind=0);
    PastryRequestMessage(const PastryRequestMessage& other);
    virtual ~PastryRequestMessage();
    PastryRequestMessage& operator=(const PastryRequestMessage& other);
    virtual PastryRequestMessage *dup() const {return new PastryRequestMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual TransportAddress& getSendStateTo();
    virtual const TransportAddress& getSendStateTo() const {return const_cast<PastryRequestMessage*>(this)->getSendStateTo();}
    virtual void setSendStateTo(const TransportAddress& sendStateTo_var);
    virtual int getPastryReqType() const;
    virtual void setPastryReqType(int pastryReqType_var);
};

inline void doPacking(cCommBuffer *b, PastryRequestMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PastryRequestMessage& obj) {obj.parsimUnpack(b);}


#endif // _PASTRYMESSAGE_M_H_
