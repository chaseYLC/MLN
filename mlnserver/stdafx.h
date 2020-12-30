﻿#pragma once

#pragma warning(disable: 4819)	// for spdlog-circular_q.h
#pragma warning(disable: 4312)	// for lockfreeLinkedlist.h


#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_UNWRAP
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION

#include <boost/asio.hpp>
#include <boost/atomic.hpp>
#include <boost/bind.hpp>
#include <boost/chrono.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/format.hpp>
#include <boost/function.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/pool/pool.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/unordered_map.hpp>
#include <cstdint>
#include <iostream>
#include <memory>
#include <random>

#include <net/logManager.h>



inline std::shared_ptr< boost::asio::io_context > shared_ioc
 = std::make_shared<boost::asio::io_context>();

typedef struct tagTSV_ID {
	enum {
		DB_ERROR = 1,

		REDIS_CLIENT = 2,
	};
}TSV_ID;

#define RSP_SEQ	"packetSequenceNum"
#define RSP_RC	"resultCode"
#define RSP_RM	"resultMsg"
#define RSP_OK	"OK"
#define RSP_RC_SYSTEM_ERROR		99


#ifndef MEMO
#define chSTR2(x) #x
#define chSTR(x)  chSTR2(x)
#define MEMO(desc) message(__FILE__ "(" chSTR(__LINE__) "):" #desc)
#endif


#define GET_USER(conn, spUserBase, user)	\
	std::shared_ptr<mln::UserBasis> spUserBase = conn->getUser();\
	if (!spUserBase) {\
		LOGE("none user. sessionId:{}", conn->getIdentity());\
		return;\
	}\
	std::shared_ptr<mlnserver::User> user = std::static_pointer_cast<mlnserver::User>(spUserBase)

