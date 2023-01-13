#include "tsduck.h"
#include <fstream>
// #include <inttypes.h>
TS_MAIN(MainCode);

class MPEG_TS_LearnData : public ts::Object
{
public:
    MPEG_TS_LearnData(const ts::UString& s = ts::UString()) : message(s) {}
    ts::UString message;
};

class MPEG_TS_LearnPlugin: public ts::ProcessorPlugin
{
public:
    MPEG_TS_LearnPlugin(ts::TSP*);
    virtual bool getOptions() override;
    virtual bool start() override;
    virtual bool stop() override;
    virtual Status processPacket(ts::TSPacket&, ts::TSPacketMetadata&) override;

private:
    ts::PID _pid;   
    ts::PacketCounter _count; 
    ts::PacketCounter pcr_count;

    uint64_t previousDTS = 0;
    uint64_t totalBits = 0;
    long long int totalDuration;

};
TS_REGISTER_PROCESSOR_PLUGIN(u"MPEG_TS_Learn", MPEG_TS_LearnPlugin);

MPEG_TS_LearnPlugin::MPEG_TS_LearnPlugin(ts::TSP* t) :
    ts::ProcessorPlugin(t, u"Count TS packets in one PID", u"[options]"),
    _pid(ts::PID_NULL),
    _count(0)
{
    option(u"pid", 'p', PIDVAL);
}

bool MPEG_TS_LearnPlugin::getOptions()
{
    _pid = intValue<ts::PID>(u"pid", ts::PID_NULL);
    return true;
}

bool MPEG_TS_LearnPlugin::start()
{
    0;
    return true;
}

bool MPEG_TS_LearnPlugin::stop()
{

/*----


			bool MPEG_TS_LearnPlugin::stop()
			{
				// The formula of bitrate is:
				// Total number of packets X size of packet (which is normally 188) then divide it to the time interval between packets (in sec).
				// Then to convert it into bit just multiply the answer with 8 and you will get the bit rate in bit/sec
				// This is the output of example bitrate using the sample stream
				// Bitrate = 518201(pkt) x 188(size)/32 (sec)
				// Bitrate = 3044430.875 x 8
				// Bitrate = 24,355,447 b/s

				// Assuming following captured in Process packet
				//	_bitrate += ts::PKT_SIZE;
				//
				//	firstpacket++;
				//	if(firstpacket==1)
			    	//		_start_time = std::chrono::system_clock::now();

				
				// Following is core of stop function if bitrate is to be calculated manually
				// auto end_time = std::chrono::system_clock::now();
    	
    				// auto elapsed = end_time - _start_time;
    
    				// double elapsed_in_sec = std::chrono::duaration_cast<std::chrono::seconds>(elapsed).count();
    
    				// double bit_rate = static_cast<double> (_bitrate) / elapsed_in_sec;

			}

----*/

    printf("totalbits: %d\n", totalBits);
    printf("totalDuration:%" PRIu64 "\n", totalDuration);
    double bitrateValue = (double)totalBits / (double)totalDuration;

    std::string bit_rate;

    std::ifstream inFile;
    inFile.open("my_file.txt");
    inFile >> bit_rate;
    inFile.close();
   
    //printf("PID: 0x%X (%d),\npackets(pkt): %'d,\nPCR packets: %'d,\nbitrate(b/s): %'s\n", _pid, _pid, _count, pcr_count, bit_rate.c_str());
    printf("=================================================\n");
    printf("    ||\tPID 0x%X\t:\t\t%d\n    ||\tpackets(pkt): \t\t%'d\n    || \tPCR packets: \t\t%'d\n    ||\tbitrate(b/s):\t\t%'s\n    ||\tbitrate_DTS(b/s):\t\t%f\n", _pid, _pid, _count, pcr_count, bit_rate.c_str(), bitrateValue);    
    printf("=================================================\n");

    return true;
}

ts::ProcessorPlugin::Status MPEG_TS_LearnPlugin::processPacket(ts::TSPacket& pkt, ts::TSPacketMetadata& metadata)
{

    if (pkt.getPID() != _pid) {
        _count++; 
        //------------- getting DTS---------------//
        if (pkt.hasDTS()){
            //--------- dividing with 90k to get the value in sec--------//
            uint64_t currentDTS = pkt.getDTS()/90000;
            // printf("%'d\n",pkt.getDTS());
            
            if (previousDTS < currentDTS) {
                uint64_t frameDuration = currentDTS - previousDTS;
                printf("currentDTS:%" PRIu64 "\n", currentDTS);
                printf("previousDTS:%" PRIu64 "\n", previousDTS);
                totalDuration += frameDuration;
                printf("totalDuration:%" PRIu64 "\n", totalDuration);
            }


            totalBits += ts::PKT_SIZE;
            // printf("total_bits:%d", totalBits);
            previousDTS = currentDTS;
        }
        //---------------------------------------//
        if(pkt.hasPCR()){
          pcr_count++;}

    }
    return TSP_OK;
}

int MainCode(int argc, char* argv[])
{
   
    ts::AsyncReport report(ts::Severity::Error);
    ts::TSProcessorArgs opt;
   
    opt.input = {u"http", {u"https://tsduck.io/streams/italy-sardinia-dttv/mux1rai.ts"}};

    opt.plugins = {
        {u"pattern", {u"--pid", u"4", u"DEADBEEF"}},
        {u"MPEG_TS_Learn", {u"--pid", u"5"}},
        {u"continuity", {}},
    };

    opt.output = {u"file", {u"output.ts"}};
  
    ts::TSProcessor tsproc(report);
    if (!tsproc.start(opt)) {
        return EXIT_FAILURE;
    }

    tsproc.waitForTermination();
    return EXIT_SUCCESS;
}