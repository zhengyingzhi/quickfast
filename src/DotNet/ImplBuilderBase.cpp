// Copyright (c) 2009, 2010 Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.

#include "QuickFASTDotNetPch.h"
#include "ImplBuilderBase.h"

#include <DotNet/DNMessageDeliverer.h>
#include <DotNet/StringConversion.h>
#pragma unmanaged
//#include <Messages/FieldIdentity.h>
#pragma managed

using namespace QuickFAST;
using namespace DotNet;

ImplBuilderBase::ImplBuilderBase(DNMessageDeliverer ^ deliverer)
  : deliverer_(deliverer)
  , logLimit_(0)
{
}

ImplBuilderBase::~ImplBuilderBase()
{
}


void
ImplBuilderBase::setApplicationType(const std::string & applicationType, const std::string & applicationTypeNamespace)
{
  applicationType_ = applicationType;
  applicationTypeNs_ = applicationTypeNamespace;
}

void
ImplBuilderBase::setLogLimit(unsigned short limit)
{
  logLimit_ = limit;
}

const std::string &
ImplBuilderBase::getApplicationType()const
{
  return applicationType_;
}

const std::string &
ImplBuilderBase::getApplicationTypeNs()const
{
  return applicationTypeNs_;
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int64 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uint64 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int32 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uint32 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int16 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uint16 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const int8 value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const uchar value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const Decimal& value)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}

void
ImplBuilderBase::addValue(Messages::FieldIdentityCPtr & identity, ValueType::Type type, const unsigned char * value, size_t length)
{
  throw std::logic_error("Unexpected call to MessageBuilder::addValue");
}


Messages::ValueMessageBuilder &
ImplBuilderBase::startMessage(
  const std::string & applicationType,
  const std::string & applicationTypeNamespace,
  size_t size)
{
  throw std::logic_error("Unexpected call to MessageBuilder::startMessage");
}

bool
ImplBuilderBase::endMessage(Messages::ValueMessageBuilder & messageBuilder)
{
  throw std::logic_error("Unexpected call to MessageBuilder::endMessage");
}

bool
ImplBuilderBase::ignoreMessage(Messages::ValueMessageBuilder & messageBuilder)
{
  throw std::logic_error("Unexpected call to MessageBuilder::ignoreMessage");
}

Messages::ValueMessageBuilder &
ImplBuilderBase::startSequence(
  Messages::FieldIdentityCPtr & identity,
  const std::string & applicationType,
  const std::string & applicationTypeNamespace,
  size_t fieldCount,
  Messages::FieldIdentityCPtr & lengthIdentity,
  size_t length)
{
  throw std::logic_error("Unexpected call to MessageBuilder::startSequence");
}

void
ImplBuilderBase::endSequence(
  Messages::FieldIdentityCPtr & identity,
  Messages::ValueMessageBuilder & sequenceBuilder)
{
  throw std::logic_error("Unexpected call to MessageBuilder::startSequenceEntry");
}

Messages::ValueMessageBuilder &
ImplBuilderBase::startSequenceEntry(
  const std::string & applicationType,
  const std::string & applicationTypeNamespace,
  size_t size)
{
  throw std::logic_error("Unexpected call to MessageBuilder::endSequence");
}

void
ImplBuilderBase::endSequenceEntry(Messages::ValueMessageBuilder & entry)
{
  throw std::logic_error("Unexpected call to MessageBuilder::endSequenceEntry");
}

Messages::ValueMessageBuilder &
ImplBuilderBase::startGroup(
  Messages::FieldIdentityCPtr & identity,
  const std::string & applicationType,
  const std::string & applicationTypeNamespace,
  size_t size)
{
  throw std::logic_error("Unexpected call to MessageBuilder::startGroup");
}

void
ImplBuilderBase::endGroup(
  Messages::FieldIdentityCPtr & identity,
  Messages::ValueMessageBuilder & groupBuilder)
{
  throw std::logic_error("Unexpected call to MessageBuilder::endGroup");
}

bool
ImplBuilderBase::wantLog(unsigned short level)
{
  return level >= logLimit_;
}

bool
ImplBuilderBase::logMessage(unsigned short level, const std::string & logMessage)
{
  if(level >= logLimit_)
  {
    System::String ^ value = string_cast(logMessage);
    return deliverer_->signalLogMessage(level, value);
  }
  return true;
}

bool
ImplBuilderBase::reportDecodingError(const std::string & errorMessage)
{
  System::String ^ value = string_cast(errorMessage);
  return deliverer_->signalDecodingError(value);
}

bool
ImplBuilderBase::reportCommunicationError(const std::string & errorMessage)
{
  System::String ^ value = string_cast(errorMessage);
  return deliverer_->signalCommunicationError(value);
}