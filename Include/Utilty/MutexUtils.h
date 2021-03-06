/*
 * @Author: INotFound
 * @Date: 2020-09-12 16:51:46
 * @LastEditTime: 2020-09-12 16:52:13
 */
#pragma once

namespace Magic{
    template<class T>
    class ScopedLockImpl : public Noncopyable{
    public:
        ScopedLockImpl(T& mutex)
            :m_Mutex(mutex), m_Locked(false){
            lock();
        }
        ~ScopedLockImpl(){
            unlock();
        }
    private:
        void lock(){
            if(!m_Locked){
                m_Mutex.lock();
                m_Locked = true;
            }
        }
        void unlock(){
            if(m_Locked){
                m_Mutex.unlock();
                m_Locked = false;
            }
        }
    private:
        T& m_Mutex;
        bool m_Locked;
    };

    template<class T>
    class ReadScopedLockImpl : public Noncopyable{
    public:
        ReadScopedLockImpl(T& mutex)
            :m_Mutex(mutex), m_Locked(false){
            lock();
        }
        ~ReadScopedLockImpl(){
            unlock();
        }
    private:
        void lock(){
            if(!m_Locked){
                m_Mutex.readLock();
                m_Locked = true;
            }
        }
        void unlock(){
            if(m_Locked){
                m_Mutex.unlock();
                m_Locked = false;
            }
        }
    private:
        T& m_Mutex;
        bool m_Locked;
    };

    template<class T>
    class WriteScopedLockImpl : public Noncopyable{
    public:
        WriteScopedLockImpl(T& mutex)
            :m_Mutex(mutex), m_Locked(false){
            lock();
        }
        ~WriteScopedLockImpl(){
            unlock();
        }
    private:
        void lock(){
            if(!m_Locked){
                m_Mutex.writeLock();
                m_Locked = true;
            }
        }
        void unlock(){
            if(m_Locked){
                m_Mutex.unlock();
                m_Locked = false;
            }
        }
    private:
        T& m_Mutex;
        bool m_Locked;
    };
}