//
// Generated file, do not edit! Created by opp_msgc 4.1 from overlay/quon/Quon.msg.
//

#ifndef _QUON_M_H_
#define _QUON_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <NodeHandle.h>
#include <QuonDefs.h>
#include <QuonHelper.h>
#include <CommonMessages_m.h>


static const int QUONCOMMAND_L = 8;
static const int QUONPOSITION_L = 128;
static const int QUONAOI_L = 64;
static const int QUONENTRYCOUNT_L = 32;
static const int QUONFLAG_L = 1;

#define QUON_L(msg) (QUONCOMMAND_L + QUONENTRY_L + KEY_L + QUONAOI_L)
#define QUONLIST_L(msg) (QUON_L(msg) + QUONENTRYCOUNT_L + msg->getNeighborHandleArraySize() * QUONENTRY_L)
#define QUONMOVE_L(msg) (QUONLIST_L(msg) + QUONPOSITION_L + QUONFLAG_L)
#define QUONENTRY_L (NODEHANDLE_L + QUONPOSITION_L)
// }}



/**
 * Enum generated from <tt>overlay/quon/Quon.msg</tt> by opp_msgc.
 * <pre>
 * enum QUONCommand
 * {
 *     JOIN_REQUEST = 0;
 *     JOIN_ACKNOWLEDGE = 1;
 *     NODE_MOVE = 2;
 *     NEW_NEIGHBORS = 3;
 *     NODE_LEAVE = 4;
 *     QUON_EVENT = 5;
 * }
 * </pre>
 */
enum QUONCommand {
    JOIN_REQUEST = 0,
    JOIN_ACKNOWLEDGE = 1,
    NODE_MOVE = 2,
    NEW_NEIGHBORS = 3,
    NODE_LEAVE = 4,
    QUON_EVENT = 5
};

/**
 * Class generated from <tt>overlay/quon/Quon.msg</tt> by opp_msgc.
 * <pre>
 * message QuonSelfMessage
 * {
 *     OverlayKey key;
 * }
 * </pre>
 */
class QuonSelfMessage : public ::cMessage
{
  protected:
    ::OverlayKey key_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const QuonSelfMessage&);

  public:
    QuonSelfMessage(const char *name=NULL, int kind=0);
    QuonSelfMessage(const QuonSelfMessage& other);
    virtual ~QuonSelfMessage();
    QuonSelfMessage& operator=(const QuonSelfMessage& other);
    virtual QuonSelfMessage *dup() const {return new QuonSelfMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual OverlayKey& getKey();
    virtual const OverlayKey& getKey() const {return const_cast<QuonSelfMessage*>(this)->getKey();}
    virtual void setKey(const OverlayKey& key_var);
};

inline void doPacking(cCommBuffer *b, QuonSelfMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, QuonSelfMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/quon/Quon.msg</tt> by opp_msgc.
 * <pre>
 * packet QuonMessage extends BaseOverlayMessage 
 * {
 *     int command enum(QUONCommand);
 *     NodeHandle sender;
 *     Vector2D position;
 *     double AOIsize;
 * }
 * </pre>
 */
class QuonMessage : public ::BaseOverlayMessage
{
  protected:
    int command_var;
    ::NodeHandle sender_var;
    ::Vector2D position_var;
    double AOIsize_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const QuonMessage&);

  public:
    QuonMessage(const char *name=NULL, int kind=0);
    QuonMessage(const QuonMessage& other);
    virtual ~QuonMessage();
    QuonMessage& operator=(const QuonMessage& other);
    virtual QuonMessage *dup() const {return new QuonMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getCommand() const;
    virtual void setCommand(int command_var);
    virtual NodeHandle& getSender();
    virtual const NodeHandle& getSender() const {return const_cast<QuonMessage*>(this)->getSender();}
    virtual void setSender(const NodeHandle& sender_var);
    virtual Vector2D& getPosition();
    virtual const Vector2D& getPosition() const {return const_cast<QuonMessage*>(this)->getPosition();}
    virtual void setPosition(const Vector2D& position_var);
    virtual double getAOIsize() const;
    virtual void setAOIsize(double AOIsize_var);
};

inline void doPacking(cCommBuffer *b, QuonMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, QuonMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/quon/Quon.msg</tt> by opp_msgc.
 * <pre>
 * packet QuonListMessage extends QuonMessage 
 * {
 *     NodeHandle neighborHandle[];
 *     Vector2D neighborPosition[];
 * }
 * </pre>
 */
class QuonListMessage : public ::QuonMessage
{
  protected:
    ::NodeHandle *neighborHandle_var; // array ptr
    unsigned int neighborHandle_arraysize;
    ::Vector2D *neighborPosition_var; // array ptr
    unsigned int neighborPosition_arraysize;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const QuonListMessage&);

  public:
    QuonListMessage(const char *name=NULL, int kind=0);
    QuonListMessage(const QuonListMessage& other);
    virtual ~QuonListMessage();
    QuonListMessage& operator=(const QuonListMessage& other);
    virtual QuonListMessage *dup() const {return new QuonListMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setNeighborHandleArraySize(unsigned int size);
    virtual unsigned int getNeighborHandleArraySize() const;
    virtual NodeHandle& getNeighborHandle(unsigned int k);
    virtual const NodeHandle& getNeighborHandle(unsigned int k) const {return const_cast<QuonListMessage*>(this)->getNeighborHandle(k);}
    virtual void setNeighborHandle(unsigned int k, const NodeHandle& neighborHandle_var);
    virtual void setNeighborPositionArraySize(unsigned int size);
    virtual unsigned int getNeighborPositionArraySize() const;
    virtual Vector2D& getNeighborPosition(unsigned int k);
    virtual const Vector2D& getNeighborPosition(unsigned int k) const {return const_cast<QuonListMessage*>(this)->getNeighborPosition(k);}
    virtual void setNeighborPosition(unsigned int k, const Vector2D& neighborPosition_var);
};

inline void doPacking(cCommBuffer *b, QuonListMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, QuonListMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/quon/Quon.msg</tt> by opp_msgc.
 * <pre>
 * packet QuonMoveMessage extends QuonListMessage 
 * {
 *     Vector2D newPosition;
 *     bool isBinding = false;
 * }
 * </pre>
 */
class QuonMoveMessage : public ::QuonListMessage
{
  protected:
    ::Vector2D newPosition_var;
    bool isBinding_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const QuonMoveMessage&);

  public:
    QuonMoveMessage(const char *name=NULL, int kind=0);
    QuonMoveMessage(const QuonMoveMessage& other);
    virtual ~QuonMoveMessage();
    QuonMoveMessage& operator=(const QuonMoveMessage& other);
    virtual QuonMoveMessage *dup() const {return new QuonMoveMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual Vector2D& getNewPosition();
    virtual const Vector2D& getNewPosition() const {return const_cast<QuonMoveMessage*>(this)->getNewPosition();}
    virtual void setNewPosition(const Vector2D& newPosition_var);
    virtual bool getIsBinding() const;
    virtual void setIsBinding(bool isBinding_var);
};

inline void doPacking(cCommBuffer *b, QuonMoveMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, QuonMoveMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/quon/Quon.msg</tt> by opp_msgc.
 * <pre>
 * packet QuonEventMessage extends QuonMessage
 * {
 * }
 * </pre>
 */
class QuonEventMessage : public ::QuonMessage
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const QuonEventMessage&);

  public:
    QuonEventMessage(const char *name=NULL, int kind=0);
    QuonEventMessage(const QuonEventMessage& other);
    virtual ~QuonEventMessage();
    QuonEventMessage& operator=(const QuonEventMessage& other);
    virtual QuonEventMessage *dup() const {return new QuonEventMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, QuonEventMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, QuonEventMessage& obj) {obj.parsimUnpack(b);}


#endif // _QUON_M_H_
