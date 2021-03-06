﻿#pragma once

#include <chrono>
#include <memory>
#include <net/memoryPool.h>
#include <net/user/userBasis.h>
#include <net/json/json.h>

namespace mlnserver {

	using TyUserIDX = int32_t;

	class Room;

	class User
		: public mln::UserBasis
		, public mln::MemoryPool< mlnserver::User >
	{
	public:
		User(mln::Connection::sptr conn)
			: UserBasis(conn)
		{}
		std::string GetForceClosingInfo();
		std::string GetUserID() const override;

		int sendJsonPacket(const std::string& url, Json::Value& jv);

	public:
		TyUserIDX m_userIDX = 0;
		std::weak_ptr<Room> m_wpRoom;
	};
};// namespace mlnserver {


#define GET_USER(conn, spUserBase, user)	\
	std::shared_ptr<mln::UserBasis> spUserBase = conn->getUser();\
	if (!spUserBase) {\
		LOGE("none user. sessionId:{}", conn->getIdentity());\
		return;\
	}\
	std::shared_ptr<mlnserver::User> user = std::static_pointer_cast<mlnserver::User>(spUserBase)


