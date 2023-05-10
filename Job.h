
#ifndef __RUBIS_JOB_H
#define __RUBIS_JOB_H

#include <vector>
#include "Job_m.h"

class JobList;



class Job: public Job_Base
{
    friend class JobList;
    protected:
        Job *parent = nullptr;
        std::vector<Job*> children;
        JobList *jobList;
        virtual void setParent(Job *parent); // only for addChild()
        virtual void parentDeleted();
        virtual void childDeleted(Job *child);
    public:
        Job(const char *name=nullptr, int kind=0, JobList *table=nullptr);

        /** Copy constructor */
        Job(const Job& job);

        /** Destructor */
        virtual ~Job();

        /** Duplicates this job */
        virtual Job *dup() const override {return new Job(*this);}

        /** Assignment operator. Does not affect parent, children and jobList. */
        Job& operator=(const Job& job);

        /** @name Parent-child relationships */
        //@{
        /** Returns the parent job. Returns nullptr if there's no parent or it no longer exists. */
        virtual Job *getParent();

        /** Returns the number of children. Deleted children are automatically removed from this list. */
        virtual int getNumChildren() const;

        /** Returns the kth child. Throws an error if index is out of range. */
        virtual Job *getChild(int k);

        /** Marks the given job as the child of this one. */
        void addChild(Job *child);

        /** Same as addChild(), but has to be invoked on the child job */
        virtual void makeChildOf(Job *parent);
        //@}

        /** Returns the JobList where this job has been registered. */
        JobList *getContainingJobList() {return jobList;}

};

#endif
