// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018-2019 The AXEL_Utility_Token Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>
#include <limits>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x0000011f88f2b96115058f93bba80ac1b01da8ad0531de456ec6af2666da429b"))
	(1, uint256("0x000000915360e79f8c402fab9aa13f43f24cca2fbe3d1dc4f89ee109ef093e94"))
	(457, uint256("0x00000058bc2f4af94eaa9acb0cdb68754d78eb6d2de7b9e2f950c0f6a583d707"))
	(1894, uint256("0x0d31623de3a14634fd7a6c99d46fad6de7db2ff963b27848b2f29ac06e8bdb2f"))
	(2531, uint256("0xb71112ac836268c956b4772fb138279ea54dcf5a82d3be2ac2d1e3b80b3278ff"))
	(3932, uint256("0x988e156fda1edcf6db15cb96c2aff5d92a8eb308aabbb7052349d7c355422607"))
	(9215, uint256("0xe7e1608c2fd158b98e5e897121c1a60ab054639ef95911bd799e47db2b96e24b"))
	(18437, uint256("0xbf61932847ce2ac2ab7caa1289401048113257abf6df5275811aba2de5964627"))
	(33921, uint256("0xd969c2b55ae6cbf174ad3c49dba470a6aa1205f0c325aff9910967f4e4d054a7"))

;

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
	1553254838, // * UNIX timestamp of last checkpoint block
    7799,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
	(0, uint256("0x41b5a543980937c082165bd908312e16ce900cf97c16c6e3341a6296908fb64c"))
	(1, uint256("0x4f006789dfa2472fbee5f27e01b091179b2f943d80fb4a8466d9fd7422c3428f"))
	(587, uint256("0x661a3633aa820b97bee334870b0251acdc32bba4191129b21b1bcb306d8c5ea5"))
	(1915, uint256("0xa74cb32ae0b2e914d6e92716212d763a11356baac3dc11c1e4bb877d06257426"))
	(2958, uint256("0x08705578042946d1733705f5366b7e01a1e510101a5b2a6c78e113e1e964018b"))
	(4022, uint256("0x8c2385aff99d36c20280ed8cbce73171d40338232cd1aba62043a856c4432d65"))
	(9326, uint256("0xebf329df2f7e7b7b6fa421f50dfa5c17d90bac596e1567a6dbfae73875a78be3"))
	(21245, uint256("0x968c46f409df306562539d86bd6d3807210ccfb9c9230a6d3869d376ac2ef506"))
	(35429, uint256("0x71e8dd177b0cfb278439f29fc277bbaafed91ec07ba889c7f9b9c81948248b72"))

;
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
	1553255151,
    7956,
    2000};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1552885200,
    0,
    100};


class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x5b;
        pchMessageStart[1] = 0xca;
        pchMessageStart[2] = 0x3c;
        pchMessageStart[3] = 0xbd;
        vAlertPubKey = ParseHex("0214a345c9add950bc2a23c569c40f029eb8d0385c86cfcc830a872737a98e6a5f");

        nDefaultPort = 15319;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        bnStartWork = ~uint256(0) >> 24;

        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;  // AXEL_Utility_Token: 1 minute
        nTargetSpacingSlowLaunch = 1 * 60;
        // nAntiInstamineTime = 50; // 720 blocks with 1 reward for instamine prevention
        nMaturity = 60;
        nMasternodeCountDrift = 3;
        nMaxMoneyOut = 1000000000 * COIN;

        nStartMasternodePaymentsBlock = 500;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 500;
        nModifierUpdateBlock = std::numeric_limits<decltype(nModifierUpdateBlock)>::max();

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Colorado trooper killed as Bomb Cyclone unleashes snow, high winds.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("044a001040da79684a0544c2254eb6c896fae95a9ea7b51d889475eb57ab2051f1a5858cac61ae400e90ea08015263ad40c65d36f0edf19e996972e7d2cbd13c15") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1552885200;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 635206;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000011f88f2b96115058f93bba80ac1b01da8ad0531de456ec6af2666da429b"));
        assert(genesis.hashMerkleRoot == uint256("0x56463c15d556bae01ec5443ccdc38e9d0f8c25cbfd319b9be75d67f6e1f57a57"));

        vSeeds.push_back(CDNSSeedData("seedmain-1.axel.network", "seedmain-1.axel.network"));     // Primary DNS Seeder
		vSeeds.push_back(CDNSSeedData("seedmain-2.axel.network", "seedmain-2.axel.network")); 
		vSeeds.push_back(CDNSSeedData("seedmain-3.axel.network", "seedmain-3.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedmain-4.axel.network", "seedmain-4.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedmain-5.axel.network", "seedmain-5.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedmain-6.axel.network", "seedmain-6.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedmain-7.axel.network", "seedmain-7.axel.network"));
		vSeeds.push_back(CDNSSeedData("explorer.axel.network", "explorer.axel.network"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23); // A
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 75);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 83); // p
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 9984
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x27)(0x00).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04c0656cf0cc41544190931243ab8b969e016cd50afdd97ee9b9ae85e2b0e826e5ebf5cfb11658864286a94e0c3c831a5306a9dbda7d133b1f5693dfb16c47f067";
        strObfuscationPoolDummyAddress = "AdCVPY3aiPYuJADZGZm3D6SkzLYdeKdrwj";
        nStartMasternodePayments = 1553085000; //Wednesday, March 20, 2019 12:30:00 PM GMT

    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x57;
        pchMessageStart[1] = 0x72;
        pchMessageStart[2] = 0x86;
        pchMessageStart[3] = 0xba;

        bnProofOfWorkLimit = ~uint256(0) >> 1;
        bnStartWork = bnProofOfWorkLimit;

        vAlertPubKey = ParseHex("04459DC949A9E2C2E1FA87ED9EE93F8D26CD52F95853EE24BCD4B07D4B7D79458E81F0425D81E52B797ED304A836667A1D2D422CD10F485B06CCBE906E1081FBAC");
        nDefaultPort = 25319;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;  // AXEL_Utility_Token: 1 minute
        nLastPOWBlock = 500;
        nMaturity = 60;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = std::numeric_limits<decltype(nModifierUpdateBlock)>::max();
        nMaxMoneyOut = 1000000000 * COIN;


        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1552881600;
        genesis.nNonce = 0;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x41b5a543980937c082165bd908312e16ce900cf97c16c6e3341a6296908fb64c"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("seedtest-1.axel.network", "seedtest-1.axel.network"));     // Primary DNS Seeder
		vSeeds.push_back(CDNSSeedData("seedtest-2.axel.network", "seedtest-2.axel.network"));    
		vSeeds.push_back(CDNSSeedData("seedtest-3.axel.network", "seedtest-3.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedtest-4.axel.network", "seedtest-4.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedtest-5.axel.network", "seedtest-5.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedtest-6.axel.network", "seedtest-6.axel.network"));
		vSeeds.push_back(CDNSSeedData("seedtest-7.axel.network", "seedtest-7.axel.network"));
		vSeeds.push_back(CDNSSeedData("explorer-test.axel.network", "explorer-test.axel.network"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65); // Testnet AXEL_Utility_Token addresses start with 'T'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet AXEL_Utility_Token script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet AXEL_Utility_Token BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet AXEL_Utility_Token BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet AXEL_Utility_Token BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        //convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "048ba868caa7608576609ba876a1455520679546492e2eb542c2ff8c0f97b9b72d4c8878e84c02a8b3b30823e4e0f164285f37f228aeb796e767927b6ec19029c0";
        strObfuscationPoolDummyAddress = "TYDrFzSAKSbxSsuw84AmeXxaGVVgYM37HS";
        nStartMasternodePayments = 1553085000; //Wednesday, March 20, 2019 12:30:00 PM GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;

        bnStartWork = ~uint256(0) >> 20;

        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetSpacing = 1 * 60;        // AXEL_Utility_Token: 1 minute
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1552885200;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 1;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;

        //assert(hashGenesisBlock == uint256("300552a9db8b2921c3c07e5bbf8694df5099db579742e243daeaf5008b1e74de"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fMineBlocksOnDemand = true;


    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
