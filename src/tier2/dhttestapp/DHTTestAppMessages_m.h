//
// Generated file, do not edit! Created by opp_msgc 4.1 from tier2/dhttestapp/DHTTestAppMessages.msg.
//

#ifndef _DHTTESTAPPMESSAGES_M_H_
#define _DHTTESTAPPMESSAGES_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <OverlayKey.h>
// }}



/**
 * Class generated from <tt>tier2/dhttestapp/DHTTestAppMessages.msg</tt> by opp_msgc.
 * <pre>
 * message DhtTestEntryTimer
 * {
 * 	OverlayKey key;
 * 
 * }
 * </pre>
 */
class DhtTestEntryTimer : public ::cMessage
{
  protected:
    ::OverlayKey key_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DhtTestEntryTimer&);

  public:
    DhtTestEntryTimer(const char *name=NULL, int kind=0);
    DhtTestEntryTimer(const DhtTestEntryTimer& other);
    virtual ~DhtTestEntryTimer();
    DhtTestEntryTimer& operator=(const DhtTestEntryTimer& other);
    virtual DhtTestEntryTimer *dup() const {return new DhtTestEntryTimer(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual OverlayKey& getKey();
    virtual const OverlayKey& getKey() const {return const_cast<DhtTestEntryTimer*>(this)->getKey();}
    virtual void setKey(const OverlayKey& key_var);
};

inline void doPacking(cCommBuffer *b, DhtTestEntryTimer& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, DhtTestEntryTimer& obj) {obj.parsimUnpack(b);}


#endif // _DHTTESTAPPMESSAGES_M_H_
